/// @file
/// @defgroup tools Struttura file di supporto
/// @{
#ifndef TOOLBOX_H
#define TOOLBOX_H
// =============================================================================
#include <stdbool.h>
// =============================================================================
/**
 * @brief Conta il numero di caratteri in una array di caratteri
 * @param s Indirizzo ad un array di caratteri
 * @return Numero di caratteri nell'array dato (escluso \0)
 */
int my_string_length(char *s);
// =============================================================================
/**
 * @brief Stampa su STDOUT e va a capo
 * @param s Indirizzo dellarray di caratteri da stampare
 */
void my_println(char *s);
// =============================================================================
/**
 * @brief Stampa in STDERR e va a capo
 * @param s Indirizzo dell'array di caratteri da stampare
 */
void my_printerr(char *s);
// =============================================================================
/**
 * @brief Funzione di errore
 * @param prog Indirizzo dell'array di caratteri da stampare
 * @param msg Indirizzo dell'array di caratteri da stampare
 */
void syserr(char *prog, char *msg);
// =============================================================================
/**
 * @brief Converte un numero intero senza segno in esadecimale
 * @param n Numero senza segno
 * @return Indirizzo all'array di caratteri rappresentate il numero
 */
char *my_unsigned_to_string(unsigned n);
// =============================================================================
/**
 * @brief Converte un intero in array di caratteri
 * @param n Numero intero
 * @return Indirizzo all'array di caratteri rappresentate il numero
 */
char *my_int_to_char(int n);
// =============================================================================
/**
 * @brief Concatena due array di caratteri
 * @param s1 Indirizzo del primo array
 * @param s2 Indirizzo del secondo array
 * @return Indirizzo all'array di caratteri risultato dall'unione dei due dati
 */
char *my_string_concat(char *s1, char *s2);
// =============================================================================
/**
 * @brief Controlla il successo della syscall
 * @param return_value valore di ritorno della system call
 * @param prog Indirizzo dell'array di caratteri da stampare
 * @param msg Indirizzo dell'array di caratteri da stampare
 */
void check_or_exit(int return_value, char *prog, char *msg);
// =============================================================================
/**
 * @brief Rimuove le risorse condivise prima di uscire
 */
void remove_ipc_and_exit();
// =============================================================================
/**
 * @brief Funzione registrata come signal handler del segnale di arresto
 */
void signal_remove_ipc();
// =============================================================================
#endif
/// @}
