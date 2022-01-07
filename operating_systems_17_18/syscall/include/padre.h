/// @file
/// @defgroup padre Firma delle funzioni utilizzate all'interno del file padre.c
/// @{
#ifndef PADRE_H
#define PADRE_H
// =============================================================================
#include <stdbool.h>
// =============================================================================
/**
 * @brief Wrapper del processo padre
 * @param plain_text File di input
 * @param encoded_text File di output
 * @info Se il file di output esiste, il processo termina immediatamente
 */
void padre(char *plain_text, char *encoded_text);
// =============================================================================
/**
 * @brief Crea e collega un segmento condiviso
 * @param key IDentifier del segmento condiviso
 * @param size Dimensione del segmento condiviso
 * @param flags Flags
 * @return Indirizzo del segmento condiviso appena creato e collegato
 */
void *attach_segment(key_t key, size_t size, int flags);
// =============================================================================
/**
 * @brief Carica il file di input
 * @param segment Indirizzo del segmento condiviso S1
 */
void load_file(char *segment);
// =============================================================================
/**
 * @brief Verifica che le chiavi siano corrette per tutta la lunghezza delle stringhe
 * @param input Indirizzo del segmento condiviso S1
 * @param output Indirizzo del segmento condiviso S2
 * @param lines Numero di righe del file di input ed output
 * @return true se la verifica è andata a buon fine, altrimenti false
 */
bool check_keys(char *input, unsigned *output, int lines);
// =============================================================================
/**
 * @brief Salva le chiavi trovate sul file di output
 * @param name File di output
 * @param segment_s2 Indirizzo del segmento condiviso S2
 * @param lines Numero di righe del file di input ed output
 */
void save_keys(char *name, unsigned *segment_s2, int lines);
// =============================================================================
/**
 * @brief Scollega e rimuove il segmento condiviso
 * @param attached_segment Indirizzo del segmento da scollegare e rimuvoere
 */
void detach_segment(int shmid, void *attached_segment);
// =============================================================================
#endif
/// @}
