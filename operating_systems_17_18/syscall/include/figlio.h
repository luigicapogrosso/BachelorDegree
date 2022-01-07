/// @file
/// @defgroup figlio Firma delle funzioni utilizzate all'interno del file figlio.c
/// @{
#ifndef FIGLIO_H
#define FIGLIO_H
// =============================================================================
/**
 * @brief Wrapper del processo figlio
 * @param lines Numero di linee nel file di input
 * @param shm_ptr_s1 Indirizzo del segmento condiviso S1
 * @param shm_ptr_s2 Indirizzo del segmento condiviso S2
 */
void figlio(int lines, void *shm_ptr_s1, unsigned *shm_ptr_s2);
// =============================================================================
/**
 * @brief Funzione registrata come signal handler del segnale SIGUSR1
 * @param signal Tipo del segnale intercettato
 */
void status_updated(int signal);
// =============================================================================
/**
 * @brief Deposita il messaggio di terminazione nella coda di messaggi del processo logger
 * @param queue_id IDentifier della coda
 */
void send_terminate(int queue_id);
// =============================================================================
#endif
/// @}
