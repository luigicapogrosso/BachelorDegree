#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/types.h>
#include "toolbox.h"
#include "constants.h"
// =============================================================================
int my_string_length(char *s) {
    int n_of_char;

    for (n_of_char = 0; s[n_of_char] != '\0'; n_of_char++);

    return n_of_char;
}
// =============================================================================
void my_println(char *s) {
    int len_s = my_string_length(s);
    char *result = malloc(sizeof(char) * (len_s + 1));

    result = my_string_concat(s, "\n");

    write(STDOUT, result, (len_s + 1));
}
// =============================================================================
void my_printerr(char *s) {
    int i, n_of_char = 0;

    for (i = 0; s[i] != '\0'; i++, n_of_char++) {
    }

    write(STDERR, s, n_of_char);
    write(STDERR, "\n", 1);
}
// =============================================================================
void syserr(char *prog, char *msg) {
    fprintf(stderr, "%s - Error: %s\n", prog, msg);
    perror("System error");
}
// =============================================================================
char *my_unsigned_to_string(unsigned n) {
    int i = 0, digits = 0;
    unsigned temp = n;

    while (temp != 0) {
        temp = temp / 16;
        digits++;
    }

    // 32 bit == 8 cifre esadecimali
    char *result = (char *) malloc(sizeof(char) * digits + 1);

    for (i = digits - 1; i >= 0; i--) {
        if ((n % 16) <= 9) {
            result[i] = (char) (n % 16) + '0';
        } else {
            result[i] = (char) ((n % 16) - 10) + 'A';
        }
        n = n / 16;
    }

    result[digits] = '\0';

    return result;
}
// =============================================================================
char *my_int_to_char(int n) {
    int i = 0, digits = 0;
    unsigned temp = n;

    do {
        digits++;
    } while ((temp /= 10) != 0);

    char *result = (char *) malloc(sizeof(char) * digits + 1);

    for (i = digits -1; i >= 0; i--) {
        int digit = (n % 10);
        result[i] = (char) (digit + '0');
        n /= 10;
    }

    result[digits] = '\0';

    return result;
}
// =============================================================================
char *my_string_concat(char *s1, char *s2) {
    int i;
    int index_result = 0;
    int len_s1 = my_string_length(s1);
    int len_s2 = my_string_length(s2);
    char *result = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));

    for (i = 0; i < len_s1; i++, index_result++) {
        result[index_result] = s1[i];
    }

    for (i = 0; i < len_s2; i++, index_result++) {
        result[index_result] = s2[i];
    }

    result[index_result] = '\0';

    return result;
}
// =============================================================================
void check_or_exit(int return_value, char *prog, char *msg) {
    if (return_value == -1) {
        syserr(prog, msg);
        // Invio segnale di arresto a tutti i processi
        kill(0, SIGINT);
    }
}
// =============================================================================
void remove_ipc_and_exit() {
    // Rimozione delle risorse condivise
    shmctl(shmid_s1, IPC_RMID, NULL);
	shmctl(shmid_s2, IPC_RMID, NULL);
	msgctl(queue, IPC_RMID, NULL);
	semctl(semid, 2, IPC_RMID, NULL);
}
// =============================================================================
void signal_remove_ipc() {
    remove_ipc_and_exit();
    exit(EXIT_FAILURE);
}
