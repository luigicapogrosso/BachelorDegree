#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <stdbool.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "padre.h"
#include "types.h"
#include "figlio.h"
#include "logger.h"
#include "toolbox.h"
#include "constants.h"
// =============================================================================
// Variabili globali
int input_fd;
int shmid_s1;
void *s1;
int shmid_s2;
unsigned *s2;
// =============================================================================
void padre(char *plain_text, char *encoded_text) {
    /*
    * SIGINT            (Ctrl + C)
    * SIGTERM           Termination signal
    * SIGQUIT           (Ctrl + \)
    * SIGSEGV           Invalid memory reference
    * SIGTSTP           (Ctrl + Z)
    */
    signal(SIGINT, signal_remove_ipc);
    signal(SIGTERM, signal_remove_ipc);
    signal(SIGQUIT, signal_remove_ipc);
    signal(SIGSEGV, signal_remove_ipc);
    signal(SIGTSTP, signal_remove_ipc);

    // Controllo se il file di output esiste. Se si, esco
    if (access(encoded_text, F_OK) == 0) {
        check_or_exit(-1, "padre", "Il file di output è già presente!");
    }

    // Controllo se il file di input esiste. Se no, esco
    if (access(plain_text, F_OK && R_OK) != 0) {
        check_or_exit(-1, "padre", "Il file di input non esiste!");
    }

    // Controllo se è possibile aprire il file di input
    if ((input_fd = open(plain_text, O_RDONLY, 0644)) == -1) {
        check_or_exit(-1, "Padre", "Impossibile aprire il file");
    }

    // Acquisisco il numero delle linee presenti nel file di input
    int i, c = 0, file_lines = 0, offset = 0;
    char buffer[BUFFER_SIZE];

    while ((c = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        for (i = 0; i < c; i++, offset++) {
            // Sono al termine del plain_text
            if (buffer[i] == '>') {
                // Linea trovata
                file_lines++;
                // Posizionamento al primo carattere della riga successiva
                i += offset + 4;
                /* Se l'indice per giungere al termine dell'encoded_text è
                 * maggiore del numero di byte restanti da leggere
                 */
                offset = 0;
                if (i > c) {
                    // Posizionamento nel punto specifico (temine di encoded_text)
                    lseek(input_fd, i - c + 1, SEEK_CUR);
                }
            }
        }
    }
    // Posizionamento all'inizio del file
    lseek(input_fd, 0, SEEK_SET);

    // Acquisico la lunghezza del file
    int filesize = lseek(input_fd, 1, SEEK_END);
    lseek(input_fd, 0, SEEK_SET);

    // Alloco e attacco la memoria condivisa S1 al padre
    s1 = attach_segment(SHMKEY_S1, sizeof(struct Status) + filesize, IPC_CREAT | 0666);

    // Imposto a 0 il valore della variabile id_string della struttura Status
    struct Status *status = (struct Status *) s1;
    status -> id_string = 0;

    // Alloco e attacco la memoria condivisa S2 al padere
    s2 = attach_segment(SHMKEY_S2, file_lines * sizeof(unsigned), IPC_CREAT | 0666);


    // Mi posiziono in S1, dove voglio far iniziare il file
    char *file = (char *) (sizeof(struct Status) + s1);

    // Carico il file nella memoria condivisa
    load_file(file);

    // Creo il figlio
    pid_t pid_figlio;
    if ((pid_figlio = fork()) == -1) {
        check_or_exit(-1, "Padre", "Impossibile creare il figlio");
    }

    if (pid_figlio == 0) {
        figlio(file_lines, s1, s2);
    } else {
        // Sono il padre
        pid_t pid_logger;
        if ((pid_logger = fork()) == -1) {
            check_or_exit(-1, "Padre", "Impossibile creare il logger");
        }

        if (pid_logger == 0) {
            logger();
        } else {
            // Aspetto il figlo ed il logger
            wait(&pid_figlio);
            wait(&pid_logger);

            // Controllo che le chiavi generate siano corrette
            if (check_keys(file, s2, file_lines) == true) {
                // Salvo le chiavi sul file di output
                save_keys(encoded_text, s2, file_lines);
            } else {
                my_printerr("Trovata una chiave sbagliata!\n");
            }

            // Stacco ed elimino i segmenti di memoria condivisa
            detach_segment(shmid_s1, s1);
            detach_segment(shmid_s2, s2);
        }
    }

    exit(0);
}
// =============================================================================
void *attach_segment(key_t key, size_t size, int flags) {
    int shmid = shmget(key, size, flags);

    if (shmid < 0) {
        check_or_exit(-1, "Padre", "Impossibile allocare il segmento di memoria");
    }

    char *shm = (char *) shmat(shmid, NULL, 0);

    if (shm == (void*) -1) {
        check_or_exit(-1, "Padre", "Impossibile attaccare il segmento di memoria");
    }

    if (key == SHMKEY_S1) {
        shmid_s1 = shmid;
    } else if (key == SHMKEY_S2) {
        shmid_s2 = shmid;
    }

    return shm;
}
// =============================================================================
void load_file(char *segment) {
    int i, x, offset = 0;
    char buffer[BUFFER_SIZE];

    while ((x = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        for (i = 0; i < x; i++) {
            segment[offset + i] = buffer[i];
        }
        offset += x;
    }

    if (close(input_fd) == -1) {
        check_or_exit(-1, "Padre", "Impossibile chiudere il file di input");
    }
}
// =============================================================================
bool check_keys(char *input, unsigned *output, int file_lines) {
    int line = 0;

    while (line != file_lines) {
        char *clear = (char *) malloc (sizeof(char) + 512);
        char *encrypted = (char *) malloc (sizeof(char) + 512);
        unsigned *key = (unsigned *)(output + line);

        // Sto analizzando la i-esima stringa
        line++;

        // Acquisizione del testo in chiaro
        int len = 0;
        input++;
        while (*input != '>') {
            clear[len] = *input;
            len++;
            input++;
        }
        input += 3;

        // Acquisizione del testo cifrato
        int i;
        for (i = 0; i < len; i++, input++) {
            encrypted[i] = *input;
        }
        input += 2;

        // Verifica della chiave
        for (i = 0; i < len; (i += 4)) {
            unsigned *c = (unsigned *) (clear);
            unsigned *e = (unsigned *) (encrypted);

            if ((*c ^ *key) != *e) {
                return false;
            }
            clear += 4;
            encrypted += 4;
        }
    }

    return true;
}
// =============================================================================
void save_keys(char *name, unsigned *segment_s2, int lines) {
    int fd, i, j;
    if ((fd = creat(name, S_IRWXU | S_IRWXG | S_IRWXO)) == -1) {
        check_or_exit(-1, "Padre", "Impossibile creare il file di output");
    }

    for (i = 0; i < lines; i++) {
        // Acquisizione della chiave
        unsigned *key = (unsigned *) segment_s2 + i;
        char *key_string = my_unsigned_to_string(*key);

        // Verifica se la chiave è minore di 8 caratteri (max. val. per 32 bit)
        int offset = 8 - my_string_length(key_string);

        // Composizione della stringa contente la chiave
        char *result = my_string_concat("0", "x");
        for (j = 0; j < offset; j++) {
            result = my_string_concat(result, "0");
        }
        result = my_string_concat(result, key_string);
        result = my_string_concat(result, "\n");

        // Scrittura su file della chiave
        if (write(fd, result, my_string_length(result)) == -1) {
            check_or_exit(-1, "Padre", "Impossibile scrivere sul file di output");
        }

        free(key_string);
        free(result);
    }

    if (close(fd) == -1) {
        check_or_exit(-1, "Padre", "Impossibile chiudere il file di output");
    }
}
// =============================================================================
void detach_segment(int shmid, void *attached_segment) {
    if (shmdt(attached_segment) == -1) {
        check_or_exit(-1, "Padre", "Impossibile staccare il segmento di memoria");
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        check_or_exit(-1, "Padre", "Impossibile cancellare il segmento di memoria");
    }
}
// =============================================================================
