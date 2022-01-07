/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Definita la grandezza dell'array questo programma lo inizializza
 * con numeri casuali compresi tra due valori min e max inseriti dall’utente.
 * Il valore max non puo' essere minore del valore min.
 * Il programma presenterà un output come da esempio:
 *
 * Inserisci un valore min: 1
 * Inserisci un valore max: 0
 * Inserisci un valore max: 100
 * 23 56 100 78 1 24 8 12 77 64
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// =============================================================================
int main()
{
    int dim, min, max, i;

    // Setto il seme iniziale
    srand(time(NULL));

    // Acquisizione della dimensione dell'array
    printf("Inserire la grandezza dell'array: ");
    scanf("%i", &dim);

    // Dichiarazione dell'array
    int array[dim];

    // Acquisizione di min e max
    printf("Inserire il numero minimo: ");
    scanf("%i", &min);
    printf("Inserire il numero massimo ");
    scanf("%i", &max);

    // Controllo che max > min
    while (min > max) {
        printf("Inserire il numero massimo ");
        scanf("%i", &max);
    }

    // Riempo l'array di valori casuali con massimo incluso
    for (i = 0; i < dim; i++) {
        array[i] = (rand() % (max - min + 1) + min);
    }

    // Stampa dell'array
    for (i = 0; i < dim; i++) {
        printf ("%i ", array[i]);
    }

    // Per ordine, a capo
    printf("\n");
}
