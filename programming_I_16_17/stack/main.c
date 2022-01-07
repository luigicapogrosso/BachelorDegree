/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
// =============================================================================
int main()
{
    char scelta;
    int valore;
    struct entry_t *stack = NULL;

    do {
        print_menu();
        scanf(" %c", &scelta);

        switch(scelta) {
            case '+':
                printf("Il valore da inserire: ");
                scanf("%i", &valore);
                stack = push(stack, valore);
                print_stack(stack);
                break;
            case '-':
                stack = pop(stack);
                print_stack(stack);
                break;
            case 't':
                printf("\nCima dello stack: %i\n\n", top(stack));
                break;
            default:
                printf("Selezione non valida!\n");
        }
    } while (scelta != 'q');
}
