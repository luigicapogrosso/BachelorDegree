#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include "types.h"
#include "logger.h"
#include "toolbox.h"
#include "constants.h"
// =============================================================================
// Variabili globali
int queue;
// =============================================================================
void logger() {

    // Registro la funzione catch_alarm come signal handler del segnale SIGALRM
    signal(SIGALRM, catch_alarm);

    // Creo la coda dei messaggi
    if ((queue = msgget(MSG_KEY, (0666 | IPC_CREAT))) == -1) {
        check_or_exit(-1, "Logger", "Impossibile creare la coda dei messaggi");
    }

    while (polling_receive(queue) != 1) {
        alarm(1);
    }

    // Elimino la cosa dei messaggi
    if (msgctl(queue, IPC_RMID, NULL) == -1) {
        check_or_exit(-1, "Logger", "Impossibile cancellare la coda dei messaggi");
    }

    exit(0);
}
// =============================================================================
void catch_alarm(int signal) {
    if (signal == SIGALRM) {
        return;
    }
}
// =============================================================================
int polling_receive(int queue_id) {
    int status;
    int exit_status = 0;
    struct Message message;
    int msg_size = sizeof(struct Message);

    while (exit_status != 1 && (status = msgrcv(queue_id, &message, msg_size, 0, 0)) > 0) {
        if (message.mtype == 1) {
            exit_status = 1;
        }
        my_println(message.text);
    }

    return exit_status;
}
// =============================================================================
