#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/msg.h>
#include "types.h"
#include "figlio.h"
#include "nipote.h"
#include "toolbox.h"
#include "constants.h"
// =============================================================================
// Variabili globali
void *s1;
int semid;
unsigned *s2;
struct sembuf *sops;
struct Status *status;
// =============================================================================
void figlio(int lines, void *shm_ptr_s1, unsigned *shm_ptr_s2) {
    // Setto il valore del puntatore al segmento di memoria S1
    s1 = shm_ptr_s1;

    // Setto il valore del puntatore al segmento di memoria S2
    s2 = shm_ptr_s2;

    // Registro la funzione status_uptaded come signal handler del segnale SIGUSR1
    signal(SIGUSR1, status_updated);

    // Recupero la coda creata dal logger
    int queue;
    if ((queue = msgget(MSG_KEY, (IPC_CREAT | 0666))) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile accedere alla coda");
    }

    // Creo un array di semafori di lunghezza 2
    if ((semid = semget(SEM_KEY, 2, IPC_CREAT | 0666)) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile creare il semaforo");
    }

    // Inizializzo il primo semaforo ad 1
    struct sembuf *sops = (struct sembuf*) malloc(sizeof(struct sembuf));
    sops -> sem_num = 0;        // Semaforo su cui l'operazione viene applicata
    sops -> sem_op = 1;         // Incremento il semaforo a 1
    sops -> sem_flg = 0;
    if (semop(semid, sops, 1) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile impostare il primo semaforo a 1");
    }

    // Inizializzo il secondo semaforo a 0
    sops -> sem_num = 1;
    sops -> sem_op = 0;
    sops -> sem_flg = 0;
    if (semop(semid, sops, 1) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile impostare il secondo semaforo a 0");
    }

    free(sops);

    // Mi posiziono all'inizio di S1, dove è contenuta la struttura Status
    status = (struct Status *) shm_ptr_s1;

#ifdef THREADS
    int t, i;
    struct Threads_data data[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    for (t = 0; t < NUM_THREADS; t++) {
        data[t].pid = getpid();
        data[t].id = t + 1;
        data[t].lines = lines;

        if (pthread_create(&threads[t], NULL, nephew, (void *)&data[t])) {
            check_or_exit(-1, "Figlio", "Impossibile lanciare la thread");
        }
    }

    // Attendo tutte le threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
#else
    // Creo il nipote 1
    pid_t pid_nipote1;
    if ((pid_nipote1 = fork()) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile creare il nipote1");
    }

    if (pid_nipote1 == 0) {
        // Sono il nipote1
        pid_t my_pid = getpid();
        nipote(my_pid, 1, lines, s1, s2);
    }

    // Sono il padre
    pid_t pid_nipote2;
    if ((pid_nipote2 = fork()) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile creare il nipote2");
    }

    if (pid_nipote2 == 0) {
        // Sono il nipote2
        pid_t my_pid = getpid();
        nipote(my_pid, 2, lines, s1, s2);
    }

    // Sono il padre
    // Aspetto nipote 1 e nipote 2
    wait(&pid_nipote1);
    wait(&pid_nipote2);
#endif
    // Rimuovo i semafori
    if (semctl(semid, 2, IPC_RMID) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile rimuovere il semaforo");
    }

    // Invio il messaggio di fine ricerca
    send_terminate(queue);

    exit(0);
}
// =============================================================================
void status_updated(int signal) {
    if (signal == SIGUSR1) {
        char *grandson = my_int_to_char(status -> grandson);
        char *id_string = my_int_to_char(status -> id_string);

        // Composizione della stringa
        char *str = my_string_concat("Il nipote ", grandson);
        str = my_string_concat(str, " sta analizzando la ");
        str = my_string_concat(str, id_string);
        str = my_string_concat(str, "-esima stringa.");

        my_println(str);

        free(grandson);
        free(id_string);
        free(str);

        unlock(1);
    }
}
// =============================================================================
void send_terminate(int queue_id) {
    int i;
    struct Message message;
    int msg_size = sizeof(struct Message);

    char *str = "Ricerca terminata";

    message.mtype = 1;
    for (i = 0; i < my_string_length(str); i++) {
        message.text[i] = str[i];
    }

    message.text[i + 1] = '\0';

    if (msgsnd(queue_id, &message, msg_size, 0) == -1) {
        check_or_exit(-1, "Figlio", "Impossibile inviare il messaggio di ricerca terminata");
    }
}
// =============================================================================
void *nephew(void *ptr) {
    struct Threads_data *data = (struct Threads_data *) ptr;
    nipote(data -> pid, data -> id, data -> lines, s1, s2);
}
// =============================================================================
