/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Il codice di Vigenere è un codice che si basa sull’utilizzo di un quadrato
 * (quadrato di Vigenre) per cifrare un messaggio di testo utilizzando una
 * chiave (parola o frase segreta); se ne propone una versione semplificata che
 * al posto delle frasi utilizza dei numeri.
 * Per i cenni storici e la versione completa, qui [1].
 * Il programma presenterà un output come da esempio:
 *
 * Inserire la sequenza numerica di 9 cifre: 123456789
 * Inserire la chiave di cifratura di 9 cifre: 111111111
 * La codifica e': 023456789
 * La decodifica e': 123456789
 *
 * [1] = https://it.wikipedia.org/wiki/Cifrario_di_Vigenère
 */

// =============================================================================
#include <stdio.h>
// =============================================================================
int main()
{
    // Coordinate
    int x, y;

    // Array per il messaggio, la chiave codifica e decodifica
    char messaggio[9] = { }, chiave[9] = { }, codifica[9] = { },
         decodifica[9] = { };

    // Dichiarazione della matrice di Vigenre
    int vigenere_matrix[10][10];

    // Creazione e stampa della matrice di Vigenre
    printf("Stampa del riquadro di Vigenere:\n");
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            vigenere_matrix[x][y] = ((x + y) % 10);
            printf("%2i",vigenere_matrix[x][y]);
        }
        printf("\n");
    }

    // Acquisiszione del messaggio da cifrare
    printf("Inserire la sequenza numerica di 9 cifre: ");
    scanf(" %c%c%c%c%c%c%c%c%c",
        &messaggio[1], &messaggio[2], &messaggio[3],
        &messaggio[4], &messaggio[5], &messaggio[6],
        &messaggio[7], &messaggio[8], &messaggio[9]);

    // Acquisizionde della chave di cifratura
    printf("Inserire la chiave di cifratura di 9 cifre: ");
    scanf(" %c%c%c%c%c%c%c%c%c",
        &chiave[1], &chiave[2], &chiave[3],
        &chiave[4], &chiave[5], &chiave[6],
        &chiave[7], &chiave[8], &chiave[9]);

    // Codifica del messaggio
    for (x = 0; x < 15; x++) {
        codifica[x] = vigenere_matrix[messaggio[x] - '0'][chiave[x % 9] - '0'];
    }

    // Stampa della codifica
    printf("La codifica e': ");
    for (x = 0; x < 9; x++) {
        printf("%i", codifica[x]);
    }
    printf("\n");

    // Decodifica del messaggio
    for (x = 0; x < 9; x++) {
        y = 0;
        while (vigenere_matrix[chiave[x % 9] - '0'][y] != codifica[x]) {
            y++;
        }
        decodifica[x] =  y;
    }

    // Stampa della decodifica
    printf("La decodifica e': ");
    for (x = 0; x < 9; x++) {
        printf ("%i", decodifica[x]);
    }

    // Per ordine, a capo
    printf("\n");

    return 0;
}
