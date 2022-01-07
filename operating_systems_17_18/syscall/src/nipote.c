#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#ifdef THREADS
#include <pthread.h>
#endif
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <sys/types.h>
#include "types.h"
#include "nipote.h"
#include "toolbox.h"
#include "constants.h"
// =============================================================================
// Variabili globali
int semid;
void *s1;
int queue;
unsigned *s2;
struct Status *status;
// =============================================================================
void nipote(pid_t pid, int id, int lines, void *shm_ptr_s1, unsigned *shm_ptr_s2) {
    int uid = id;
    int my_string = 0;

    // Setto il valore del puntatore al segmento di memoria S1
    s1 = shm_ptr_s1;

    // Setto il valore del puntatore al segmento di memoria S2
    s2 = shm_ptr_s2;

    // Recupero il semaforo creato dal padre
    if ((semid = semget(SEM_KEY, 2, 0666)) == -1) {
        check_or_exit(-1, "Nipote", "Impossibile recuperare semaforo");
    }

    // Recupero la coda creata dal logger
    if ((queue = msgget(MSG_KEY, (IPC_CREAT | 0666))) == -1) {
        check_or_exit(-1, "Nipote", "Impossibile accedere alla coda");
    }

    // Mi posiziono in S1, dove inizia il file
    char *file = (char *) (sizeof (struct Status) + s1);

    // Mi posiziono all'inizio di S1, dove è contenuta la struttura Status
    status = (struct Status *) s1;

    while ((my_string = get_my_string(lines, uid)) >= 0) {
        unsigned key;
        char *string;
        // Leggo la stringa dal segmento S1
        string = load_string(file, my_string);

        // Trovo la chiave
        key = find_key(string);

        // Salvo la chiave
        save_key(key, s2, my_string);
    }
#ifdef THREADS
    pthread_exit(0);
#else
    exit(0);
#endif
}
// =============================================================================
int get_my_string(int l, int id) {
    lock(0);
    int my_string = status -> id_string;
    if (my_string > l - 1) {
        unlock(0);
        return -1;
    } else {
        status -> grandson = id;
        status -> id_string = status -> id_string + 1;
#ifdef THREADS
        // Invio il segnale SIGUSR1 a me stesso
        kill(getpid(), SIGUSR1);
#else
        // Invio il segnale SIGUSR1 al processo figlio
        kill(getppid(), SIGUSR1);
#endif
        lock(1);
        unlock(0);

        return my_string;
    }
}
// =============================================================================
void lock(int id) {
    struct sembuf *sops = (struct sembuf*) malloc(sizeof(struct sembuf));
    sops -> sem_num = id;
    sops -> sem_op = -1;
    sops -> sem_flg = 0;

    if (semop(semid, sops, 1) == -1) {
        check_or_exit(-1, "Nipote", "Impossibile bloccare il semaforo");
    }

    free(sops);
}
// =============================================================================
char *load_string(char *segment, int line) {
    int i = 0, offset = 0;
    char *string = malloc(sizeof(char) * 1030);

    // Posizionamento nella punto corretto del file
    while (i != line) {
        if (*segment == '>') {
            segment += (offset + 4);
            i++;
            offset = 0;
        } else {
            segment++;
            offset++;
        }
    }

    // Acquisiziane del plain_text
    int len = 0;
    for (i = 0; *segment != ';'; i++, len++, segment++) {
        string[i] = *segment;
    }

    // Acquisizione dell'encoded_text
    while (len + 1 != 0) {
        string[i] = *segment;
        len--;
        i++;
        segment++;
    }

    string[i] = '\0';

    return string;
}
// =============================================================================
unsigned find_key(char *string) {
    struct timeval ts;

    // Acquisisco i secondi d'inizio
    gettimeofday(&ts, NULL);
    time_t start = ts.tv_sec;

    // Acquisizione dei primi 4 byte del plain_text
    unsigned *clear = (unsigned *)(string + 1);

    int i = 0;
    while (string[i] != ';') {
        i++;
    }

    // Acquisizione dei primi 4 byte dell'encoded_text
    unsigned *encrypted = (unsigned *)(string + i + 2);

    unsigned key = 0;
    while ((*clear ^ key) != *encrypted) {
        key++;
    }

    // Acquisisco i secondi di fine
    gettimeofday(&ts, NULL);
    time_t end = ts.tv_sec;

    send_timeelapsed(end - start);

    return key;
}
// =============================================================================
void save_key(unsigned key, unsigned *segment, int line) {
    unsigned *pos = (unsigned *) segment + (line);
    *pos = key;
}
// =============================================================================
void unlock(int id) {
    struct sembuf *sops = (struct sembuf*) malloc(sizeof(struct sembuf));
    sops -> sem_num = id;
    sops -> sem_op = 1;
    sops -> sem_flg = 0;

    if (semop(semid, sops, 1) == -1) {
        check_or_exit(-1, "Nipote", "Impossibile sbloccare il semaforo");
    }

    free(sops);
}
// =============================================================================
void send_timeelapsed(time_t time) {
    int i, j;
    struct Message message;
    int msg_size = sizeof(struct Message);

    char *str_num = my_int_to_char((int) time);
    char *str = my_string_concat("Chiave trovata in ", str_num);

    message.mtype = 2;
    for (i = 0; i < my_string_length(str); i++) {
        message.text[i] = str[i];
    }

    message.text[i] = '\0';

    if (msgsnd(queue, &message, msg_size, 0) == -1) {
        check_or_exit(-1, "Nipote", "Impossibile inviare il messaggio relativo al calcolo della chiave");
    }

    free(str_num);
    free(str);
}
// =============================================================================
