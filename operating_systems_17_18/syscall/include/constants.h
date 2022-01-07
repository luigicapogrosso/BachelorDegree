/// @file
/// @defgroup costanti Costanti globali
/// @{
#ifndef CONSTANTS_H
#define CONSTANTS_H
// =============================================================================
/**
 * @brief Descrittore dello standard input
 */
#ifndef STDOUT
#define STDOUT 1
#endif
// =============================================================================
/**
 * @brief Descrittore dello standard error
 */
#ifndef STDERR
#define STDERR 2
#endif
// =============================================================================
/**
 * @brief Dimensione del buffer per le operazioni di lettura e scrittura
 */
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif
// =============================================================================
/**
 * @brief Chiave del segmento condiviso S1
 */
#ifndef SHMKEY_S1
#define SHMKEY_S1 11111
#endif
// =============================================================================
/**
 * @brief Chiave del segmento condiviso S2
 */
#ifndef SHMKEY_S2
#define SHMKEY_S2 22222
#endif
// =============================================================================
/**
 * @brief Chiave del semaforo
 */
#ifndef SEM_KEY
#define SEM_KEY 33333
#endif
// =============================================================================
/**
 * @brief Chiave della coda dei messaggi
 */
#ifndef MSG_KEY
#define MSG_KEY 44444
#endif
// =============================================================================
/**
 * @brief Numero di thread
 */
#ifdef THREADS
#define NUM_THREADS 4
#endif
// =============================================================================
/// IDentifier del segmento condiviso S1
extern int shmid_s1;
/// IDentifier del segmento condiviso S2
extern int shmid_s2;
/// IDentifier della coda dei messaggi
extern int queue;
/// IDentifier del semaforo
extern int semid;
// =============================================================================
#endif
/// @}
