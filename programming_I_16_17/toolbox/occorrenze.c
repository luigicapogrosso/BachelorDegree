/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Nel file viene dato un main in cui si è già inizializzato l’array m
 * con numeri interi compresi tra 0 e 10.
 * E stato poi implementato il processo che porta al calcolo, ed infine
 * alla stampa del numero di occorrenze dei numeri presenti all'interno
 * dell'array m.
 * Il programma presenterà un output come da esempio:
 *
 * 0 -> 2; 1 -> 3; 2 -> 0; 3 -> 1; 4 -> 0; 5 -> 0;
 * 6 -> 1; 7 -> 0; 8 -> 0; 9 -> 3;
 */

// =============================================================================
 #include <stdio.h>
// =============================================================================
 int main()
 {
     int i, j, temp, counter = 0;

     // Dichiarazione e inizializzazione dell'array
     int m[10] = {1, 9, 6, 0, 1, 9, 9, 3, 0, 1};

     // Genero i numeri da 1 a 10
     for (i = 0; i < 10; i++) {
         temp = i;
         // Per ogni n, verifico le occcorrenze nell' array
         for (j = 0; j < 10; j++) {
             if (m[j] == temp) {
                counter += 1;
            }
         }
         // Stampa
         printf("%i -> %i; ", temp, counter);
         counter = 0;
     }

    // Per ordine, a capo
    printf("\n");
}
