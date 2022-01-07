/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Definito un array e propria grandezza inserita dall'utente (che in questo
 * esempio deve essere popolato da parte dell'utente), tale programma ne
 * restituisce un secondo che abbia in prima posizione ultimo elemento
 * dell'array di partenza, in seconda posizione il penultimo elemento
 * dell'array di partenza, e così via.
 * Il programma presenterà un output come da esempio:
 *
 * Stampa dell'array: 1 2 3 9 58 56 32 2 98 45
 * Stampa dell'array ruotato: 45 98 2 32 56 58 9 3 2 1
 */

// =============================================================================
#include <stdio.h>
// =============================================================================
void ruota_array (int array[], int n);
// =============================================================================
int main()
{
    int dim, i;

    // Acquisizione della dimensione dell'array
    printf("Inserire la grandezza dell'array: ");
    scanf("%i", &dim);

    // Dichiarazione dell'array
    int array[dim];

    // Popolamento dell'array
    for (i = 0; i < dim; i++) {
        // Il print parte da 1, ma memorizza in 0
        printf("Inserire numero %i: ", (i + 1));
        scanf("%i", &array[i]);
    }

    // Stampa dell'array
    printf("Stampa dell'array: ");
    for (i = 0; i < dim; i++) {
        printf("%i ", array[i]);
    }

    // Per ordine, a capo
    printf("\n");

    // Rotazione e stampa dell'array mediate apposita funzione
    ruota_array(array, dim);
}
// =============================================================================
void ruota_array (int array[], int n)
{
    int i, temp = 0, j = 0;
    int array_finale[n] ;

    // Genero l'array ruotato
    for (i = (n - 1); i >= 0; i--) {
        temp = array[i];
        array_finale[j] = temp;
        j += 1;
    }

    // Stampa dell'array ruotato
    printf("Stampa dell'array ruotato: ");
    for (i = 0; i < n; i++) {
        printf("%i ", array_finale[i]);
    }

    // Per ordine, a capo
    printf("\n");
}
