/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Programma per disporre un array di interi in ordine crescente attravero
 * la funzione sort che implemente il processo con una serie di cicli for
 * annidati fra loro.
 * Il programma presenterà un output come da esempio:
 * Array iniziale:
 * 95 632 12 35 845 62 12 325 36
 * Array ordinato:
 * 12 12 35 36 62 95 325 632 845
 */

// =============================================================================
#include <stdio.h>
// =============================================================================
void sort(int array[], int n);
// =============================================================================
int main()
{
    int dim, i;

    // Acquizizione della dimesione dell'array
    printf("Inserire la dimensione dell'array: ");
    scanf("%i", &dim);

    // Dichiarazione dell'array
    int array[dim];

    // Popolamento dell' array
    for (i = 0; i < dim; i++) {
        // Il print parte da 1, ma memorizza in 0
        printf("Inserire numero %i: ", (i + 1));
        scanf("%i", &array[i]);
    }

    // Stampa dell' array iniziale
    printf("Array iniziale: \n");
    for (i = 0; i < dim; i++) {
        printf ("%i ", array[i]);
    }

    // Per ordine, a capo
    printf("\n");

    // Ordinamento dell' array
    sort(array, dim);

    // Stampa dell'array ordinato
    printf("Array ordinato: \n");
    for (i = 0; i < dim; i++) {
        printf ("%i ", array[i]);
    }

    // Per ordine, a capo
    printf("\n");
}
// =============================================================================
void sort(int array[], int n)
{
    int i, j, temp;

    // Ciclo su tutto l'array con pos_attuale = 0
    for (i = 0; i < n; i++) {
        // Ciclo su tutto l'array con pos_prossima = (pos_attuale + 1)
        for (j = (i + 1); j < n; j++) {
            // pos_attuale > pos_prossima
            if (array[i] > array[j]) {
                // Scambio le due posizioni
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
