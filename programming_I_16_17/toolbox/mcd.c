/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Scrivere un programma che acquisisca due numeri inseriti dall' utente e
 * e di questi ne calcoli poi l' MCD.
 * Il programma presenterà un output come da esempio:
 *
 * Inserire n1 e n2: 5 8
 * L'MCD tra 5 e 8 è: 1
 */

// =============================================================================
#include <stdio.h>
// =============================================================================
int main()
{
    int n1, n2, rest;

    // Acquisizione dei due numeri da tastiera
    printf("Inserire n1 e n2: ");
    scanf("%i%i", &n1, &n2);

    // Stampa del messaggio
    printf("L'MCD tra %i e %i è: ", n1, n2);

    // Operazione di calcolo
    while (n2 != 0) {
        rest = (n1 % n2);
        n1   = n2;
        n2   = rest;
    }

    // Stampa dell'MCD
    printf("%i\n", n1);
}
