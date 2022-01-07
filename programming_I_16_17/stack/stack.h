/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
struct entry_t {
    int value;
    struct entry_t *next;
};
// =============================================================================
// Creazione del menù di scelta
void print_menu();
// =============================================================================
// Funzione che aggiunge un nuovo elemento allo stack
struct entry_t *push(struct entry_t *s, int value);
// =============================================================================
// Funzione che elimina l'elemento in cima allo stack
struct entry *pop(struct entry_t *s);
// =============================================================================
// Funzione che restituisce l'elemento in cima allo stack
int top(struct entry_t *s);
// =============================================================================
// Funzione che stampa il contenuto di uno stack
void print_stack(struct entry_t *s);
