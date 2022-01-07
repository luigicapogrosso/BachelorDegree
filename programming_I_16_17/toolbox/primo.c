/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Scrivere un programma che richieda in input un numero, e verifichi se esso
 * primo o meno.
 * Il programma presenterà un output come da esempio:
 *
 * Inserisci n intero: 9
 * Non è primo!
 */

// =============================================================================
#include <stdio.h>
// =============================================================================
int main()
{
    int num, divisor, first = 1;

    // Forzo l'inserimento di un numero intero positivo
    do {
        printf("Inserisci n intero: ");
        scanf("%i", &num);
    } while (num < 0);

    // Verifico se esso è primo o meno
    for (divisor = 2; divisor < num; divisor++) {
        if(num % divisor == 0) {
            first = 0;
            break;
        }
    }

    // Se first è vero
    if (first) {
        printf("E' primo!\n");
    } else {
        printf("Non è primo!\n");
    }
}
