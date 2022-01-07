/// @file
/// @defgroup types Strutture utilizzate nel progetto
/// @{
#ifndef TYPES_H
#define TYPES_H
// =============================================================================
/**
 * @brief struttura di controllo dei nipoti
 */
struct Status {
    int grandson;
    int id_string;
};
// =============================================================================
/**
 * @brief struttura dei messaggi inviati a logger
 */
struct Message {
    long mtype;
    char text[128];
};
// =============================================================================
/**
 * @brief struttura dati per passaggio informazioni tra figlio e nipote/i
 */
struct Threads_data {
    int pid;
    int id;
    int lines;
};
// =============================================================================
/**
 * @brief Dichiarazione esplicita richiesta
 */
union semun {
    int val;
    struct semid_ds *buffer;
    unsigned short *array;
    struct  seminfo *__buf;
};
// =============================================================================
#endif
/// @}
