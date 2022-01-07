/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Questo esercizio, come prima richiesta presenta la dimensione dell'array
 * e successivamente richiede il popolamento di questo.
 * Il focus è quello della ricerca lineare. Difatti chiederà poi all'
 * utente di inserire il numero da ricercare, controlla se il numero è
 * presente o meno, avvisandolo attraverso un opportuno messaggio.
 * Se presente stampa a video la posizione in cui è stato trovato.
 * Il programma presenterà un output come da esempio:
 * 1 5 6 2 7 4 1 9
 * Inserire il numero da ricercare: 5
 * Il numero 5 si trova in posizione 2
 */

// =============================================================================
#include <stdio.h>
// =============================================================================
int ricerca_lineare(int array[], int n1, int n2);
// =============================================================================
int main()
{
    int i, dim, num, pos;

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
    for (i = 0; i < dim; i++) {
        printf("%i ", array[i]);
    }

    // Per ordine, a capo
    printf("\n");

    // Acquisizione del numero da ricercare
    printf("Inserire il numero da ricercare: ");
    scanf("%i", &num);

    // Ricerca lineare del numero
    pos = ricerca_lineare(array, dim, num);

    // Se ricevo 3, codificato come messaggio d'errore, stampo errore
    if (pos == 3) {
        printf("Il numero inserito non è presente!\n");
    // Atrimenti stampo la posizione
    } else {
        // Per l' untente il conteggio parte da 1, quindi pos + 1
        printf("Il numero %i si trova in posizione %i\n", num, (pos + 1));
    }
}
// =============================================================================
int ricerca_lineare(int array[], int n1, int n2)
{
    int i, pos;

    // Riecerco se all'interno dell'array vi è o meno il numero
    for (i = 0; i < n1; i++) {
        // Se si, lo ritorno indietro subito
        if (array[i] == n2) {
            pos = i;
            return pos;
        }
    }

    // Codifico 3 come errore, essendo uscito dal cilo, num assente
    return 3;
}
