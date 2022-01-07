/// @file
/// @defgroup logger Firma delle funzioni utilizzate all'interno del file logger.c
/// @{
#ifndef LOGGER_H
#define LOGGER_H
// =============================================================================
/**
 * @brief Wrapper del processo logger
 */
void logger();
// =============================================================================
/**
 * @brief Funzione registrata come signal handler del segnale SIGALRM
 * @param signal Tipo del segnale intercettato
 */
void catch_alarm(int signal);
// =============================================================================
/**
 * @brief Scarica la coda di messaggi e la stampa su STDOUT
 * @param queue_id IDentifier della coda
 * @return 0 se il logger deve continuare a stampare la coda, 1 se il logger va arrestato
 */
int polling_receive(int queue_id);
// =============================================================================
#endif
/// @}
