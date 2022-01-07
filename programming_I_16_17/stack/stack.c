/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
// =============================================================================
void print_menu()
{
    printf("Operazioni diponibili:\n");
	printf("\t+: Aggiunta di un elemento\n");
	printf("\t-: Rimozione di un elemento\n");
	printf("\tt: Visualizzazione elemento in cima\n");
	printf("\tq: Uscire\n");
	printf("Opzione desiderata: ");
}
// =============================================================================
struct entry_t *push(struct entry_t *s, int value)
{
    struct entry_t *node = (struct entry_t *) malloc(sizeof(struct entry_t));

    node -> value = value;
    node -> next = s;

    return node;
}
// =============================================================================
struct entry *pop(struct entry_t *s)
{
    if (s != NULL) {
        struct entry_t *tmp = s;
        s = s -> next ;
        free(tmp);
    }

    return s;
}
// =============================================================================
int top(struct entry_t *s)
{
	if (s != NULL) {
		return s -> value;
    }
}
// =============================================================================
void print_stack(struct entry_t *s)
{
	struct entry_t *pointer = s;

	printf("\nElementi nello stack: ");
	while (pointer != NULL) {
		printf("%i ", pointer -> value);
		pointer = pointer -> next;
	}
	printf("\n\n");
}
