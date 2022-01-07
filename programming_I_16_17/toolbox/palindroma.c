/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Il programma, attraverso una funzone ricorsiva, determina se
 * una parola è plindroma o meno.
 */

// =============================================================================
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 81
// =============================================================================
void leggi_parola(char parola[]);
bool palindroma(char *parola, int s, int l);
// =============================================================================
int main()
{
    char parola[SIZE];

    leggi_parola(parola);

    if (palindroma(parola, 0, strlen(parola))) {
        printf("La stringa è palindroma!\n");
    } else {
        printf("La stringa non è palindroma!\n");
    }
}
// =============================================================================
void leggi_parola(char parola[])
{
    printf("Inserire la parola (massimo 80 caratteri): ");
    scanf("%80s", parola);
}
// =============================================================================
bool palindroma(char *parola, int s, int l)
{
    if (l <= 1) {
        return true;
    } else {
        if ((parola[s] == parola[s + l - 1]) && palindroma(parola, s + 1, l - 2)) {
            return true;
        } else {
            return false;
        }
    }
}
