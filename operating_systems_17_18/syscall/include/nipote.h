/// @file
/// @defgroup nipote Firma delle funzioni utilizzate all'interno del file nipote.c
/// @{
#ifndef NIPOTE_H
#define NIPOTE_H
// =============================================================================
/**
 * @brief Wrapper del processo nipote
 * @param pid Process IDentifier del processo
 * @param id IDentifier del processo
 * @param lines Numero di linee nel file di input
 * @param shm_ptr_s1 Indirizzo del segmento condiviso S1
 * @param shm_ptr_s2 Indirizzo del segmento condiviso S2
 */
void nipote(pid_t pid, int id, int lines, void *shm_ptr_s1, unsigned *shm_ptr_s2);
// =============================================================================
/**
 * @brief Wrapper del processo figlio (utilizzato dalle thread)
 * @param ptr Indirizzo alla struttura dati contenente i parametri formali
 */
void *nephew(void *ptr);
// =============================================================================
/**
 * @brief Blocca l'accesso esclusivo alla regione critica
 * @param id IDentifier del semaforo
 */
void lock(int id);

// =============================================================================
/**
 * @brief Acquisisce la stringa dal segmento condiviso S1
 * @param segment Indirizzo del file contentuto nel segmento condiviso S1
 * @param line Linea i-esima acquisita
 * @return Linea i-esima richiesta
 */
char *load_string(char *segment, int line);
// =============================================================================
/**
 * @brief Trova la chiave di cifratura
 * @param string Linea i-esima da analizzare
 * @return Chiave trovata
 */
unsigned find_key(char *string);
// =============================================================================
/**
 * @brief Salva la chiave nel segmento condiviso S2
 * @param key Chiave da salvare
 * @param segment Indirizzo del segmento condiviso S2 dove verrà salvata la chiave
 * @param line Indice della chiave (la "riga" del segmento del segmento condiviso S2)
 */
void save_key(unsigned key, unsigned *segment, int line);
// =============================================================================
/**
 * @brief Sblocca l'accesso esclusivo alla regione critica
 * @param id IDentifier
 */
void unlock(int id);
// =============================================================================
/**
 * @brief Deposita il messaggio "chiave trovata in ", nella coda di messagi del processo logger
 * @param time Intervallo di tempo che verrà concatenato al messaggio da depositare
 */
void send_timeelapsed(time_t time);
// =============================================================================
/**
 * @brief Acquisizione della i-esima stringa
 * @param l Numero di linee nel file di input
 * @param id IDentifier del processo
 */
int get_my_string(int l, int id);
// =============================================================================
#endif
/// @}
