/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Data una matrice A di dimensione nxn, ed una matrice B di dimensione nxn, il
 * risultato del  prodotto matriciale AxB è una nuova matrice di dimensioni
 * nxn tale che C[i][j] = <SOMMATORIA n-1> (A[i][r] * B[r][j]).
 *
 * Si scriva un programma che:
 * - costruisce due matrici di dimensione 10x10;
 * - le riempe con  numeri casuali da 0 a 50;
 * - calcola il prdotto matriciale;
 * - stampa il risultato.
 * Il programma presenterà il seguente output:
 *
 * 15    50    22    30     1    35    20    28    20    46
 *  4    26    18    45    29    22    10     0    42    11
 * 28    19     4    21    32     2    11    33    10     1
 * 33    26     0     4     5     2    14    25     4    34
 * 20    33    34    12     2    12    34    12    38     0
 * 49    15    19    27    37    26    29    22     8    40
 * 23    41    15    49    20    20    25     8    46    29
 * 16    40    36     0     2    38    12    10    25    50
 * 35    23    40    29    50     0     4     3    22    37
 * 43    45     1     7    43    21     1    17     3    21
 *
 * 20    20    36     6    20    12    18    32    22    17
 *  6    32    14    46    10    39    46    14    42    42
 *  0    34    10     1    15     3    48    16    45    25
 * 12    40    45    48    20    14     9    12    21     5
 * 30     1    37    44    21    47     6    41    35    48
 * 32     9     5    42    36    45    19    33    11    39
 * 32    48    28    27    45    22    15     3    34    36
 *  8    38    11    20     6    32    41    12    22    26
 * 35     3    35    40    20    45    35    39     1    20
 *  1    34    17    29    10    11    25    25    39     9
 *
 * 2700  2700  4860   810  2700  1620  2430  4320  2970  2295
 *  720   720  1296   216   720   432   648  1152   792   612
 * 5040  5040  9072  1512  5040  3024  4536  8064  5544  4284
 * 5940  5940 10692  1782  5940  3564  5346  9504  6534  5049
 * 3600  3600  6480  1080  3600  2160  3240  5760  3960  3060
 * 8820  8820 15876  2646  8820  5292  7938 14112  9702  7497
 * 4140  4140  7452  1242  4140  2484  3726  6624  4554  3519
 * 2880  2880  5184   864  2880  1728  2592  4608  3168  2448
 * 6300  6300 11340  1890  6300  3780  5670 10080  6930  5355
 * 7740  7740 13932  2322  7740  4644  6966 12384  8514  6579
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
// =============================================================================
void popolazione_matrice(int M[SIZE][SIZE]);
void stampa_matrice(int M[SIZE][SIZE]);
void prodotto_matrice(int M[SIZE][SIZE], int N[SIZE][SIZE], int L[SIZE][SIZE]);
// =============================================================================
int main()
{
    int i, j;

    // Dichiarazione delle matrici
    int A[SIZE][SIZE] = { };
    int B[SIZE][SIZE] = { };
    int C[SIZE][SIZE] = { };

    // Setto il seme inziale
    srand(time(NULL));

    // Popolazione con numeri casuali di A
    popolazione_matrice(A);

    // Popolazione con numeri casuali di B
    popolazione_matrice(B);

    // Stampa di A
    stampa_matrice(A);

    // Per ordine, a capo
    printf("\n");

    // Stampa di B
    stampa_matrice(B);

    // Per ordine, a capo
    printf("\n");

    // Prodotto delle due matrici, A e B
    prodotto_matrice(A, B, C);

    // Stampa di C (matrice prodotto)
    stampa_matrice(C);

    // Per ordine, a capo
    printf("\n");
}
// =============================================================================
void popolazione_matrice(int M[SIZE][SIZE])
{
    int i, j;

    // Iterazione sugli elementi della matrice
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Generazione dei valori da 0 a 50
            M[i][j] = rand() % 51;
        }
    }
}
// =============================================================================
void stampa_matrice(int M[SIZE][SIZE])
{
    int i, j;

    // Iterazione sugli elementi della matrice
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Stampa della riga con i rispettivi valori
            printf("%5d ", M[i][j]);
        }
        printf("\n");
    }
}
// =============================================================================
void prodotto_matrice(int M[SIZE][SIZE], int N[SIZE][SIZE], int L[SIZE][SIZE])
{
    int i, j, n, sum;

    // Iterazione sui valori della matrice
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            sum = 0;
            // Sommatoria del prodotto delle matrici
            for (n = 0; n < SIZE - 1; n++) {
                // Calcola della sommatoria
                sum += M[i][0] * N[0][j];
            }
            // Inserisco il valore nella corrispettiva posizione
            L[i][j] = sum;
        }
    }
}
