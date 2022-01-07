/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * ATTENZIONE:
 * Se eseguite questo comando da un terminale unix dovrete utilizzare la
 * seguente sintassi:
 * gcc zeri.c -lm
 *
 * Un'equazione della forma ax^2 + bx + c è detta equazione quadratica.
 * I valori "a", "b" e "c" rappresentano delle costanti.
 * I valori di "x" che soddisfano una particolare equazione quadratica sono
 * chiamati radici.
 * Questo programma trova le radici di una determinata equazione quadratica.
 * Il programma presenterà un output come da esempio:
 * Il polinomio è nella forma: 5x^2 + 9x + 2
 * Le radici di questa equazione sono: x1 = 0 ed x2 = -1
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// =============================================================================
int calcola_discriminate(int n1, int n2, int n3);
// =============================================================================
int main()
{
    int a, b, c, radice1, radice2, discriminante;

    // Acquisizione della costante "a"
    printf("Digitare la costante a: ");
    scanf("%i", &a);

    // Acquisizione della costante "b"
    printf("Digitare la costante b: ");
    scanf("%i", &b);

    // Acquisizione della costante "c"
    printf("Digitare la costante c: ");
    scanf("%i", &c);

    // Stampa del polinomio nella forma ax^2 + bx + c
    printf("Il polinomio è nella forma: ");
    printf("%ix^2 + %ix + %i", a, b, c);

    // Per odine, a capo
    printf("\n");

    // Acquisizione del disciminate
    discriminante = calcola_discriminate(a, b, c);

    // Verifica se il discriminante è negativo
    if (discriminante == 3) {
        // Stampa del relativo messaggio
        printf("Le radici di questa equazione sono immaginarie!");
        // Per odine, a capo
        printf("\n");
        // Fine del programma
        exit(1);
    } else {
        radice1 = ((-b + discriminante) / (2 * a));
        radice2 = ((-b - discriminante) / (2 * a));
    }

    // Se le radici sono uguali, le stapo una sola volta
    if (radice1 == radice2) {
        printf("La radice di questa equazione è: ");
        printf("x1,2 = %i", radice1);
    // Se diverse, le stampo entrambe
    } else {
        printf("Le radici di questa equazione sono: ");
        printf("x1 = %i ed x2 = %i", radice1, radice2);
    }

    // Per odine, a capo
    printf("\n");
}
// =============================================================================
int calcola_discriminate (int n1, int n2, int n3)
{
    int delta;

    delta = sqrt((n2 * n2) - (4 * n1 * n3));

    // Se delta è negativo, restituisco 3 come codifica di errore
    if (delta < 0) {
        return 3;
    // Altrimenti restituisco il delta
    } else {
        return delta;
    }
}
