/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

#define SIZE 10
// =============================================================================
int main()
{
    int i, array[SIZE];
    struct list_t *list1;
    struct list_t *list2 = NULL;
    struct list_t *list3 = NULL;
    struct list_t *list4 = NULL;
    struct list_t *list5 = NULL;
    struct list_t *list6 = NULL;

    // Utilizzo della funzione construct
    list1 = construct(2,
                construct(-5,
                    construct(3,
                         construct(8,
                             construct(-1,
                                 construct(-2,
    								 construct(8,
                                         construct(3, NULL))))))));
    printf("La lista 1 è: ");
    print_list(list1);

    // Utilizzo della funzione insert_on_head
    for (i = 0; i < 10; i++) {
        list2 = insert_on_head(list2, i);
    }
    printf("La lista 2 è: ");
    print_list(list2);

    // Utilizzo della funzione insert_on_tail
    for (i = 0; i < 10; i++) {
        list3 = insert_on_tail(list3, i);
    }
    printf("La lista 3 è: ");
    print_list(list3);

    // Utilizzo della funzione array_to_list
    for (i = 0; i < SIZE; i++) {
        array[i] = i + 10;
    }
    printf("L' array è: ");
    for (i = 0; i < SIZE; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
    list4 = array_to_list(list4, array, SIZE);
    printf("La lista 4 è: ");
    print_list(list4);

    // Utilizzo della funzione delete_xvalue
    printf("Scegliere la posizione da eliminare: ");
    scanf("%i", &i);
    list1 = delete_xvalue(list1, i);
    printf("La lista 1 è ora: ");
    print_list(list1);

    // Utilizzo della funzione merge_list
    printf("Il merge fra lista 1 e lista 2: ");
    list5 = merge_list(list1, list2);
    print_list(list5);

    // Utilizzo della funzione first_equal
    printf("Indirizzo del primo n. pari lista 1: %p\n", first_equal(list1));

    // Utilizzo della funzione minimun_equal
    printf("Indirizzo del minimo n. pari lista 1: %p\n", first_equal(list1));

    // Utilizzo della funzione read_list
    /*
     * list = read_list();
     * printf("La lista è: ");
     * print_list(list);
     */

    // Utilizzo della funzione delete_nvalue
    printf("La lista 1 senza elementi negativi è: ");
    list1 = delete_nvalue(list1);
    print_list(list1);

    // Utilizzo della funzione delete_pvalue
    printf("La lista 2 senza elementi positivi è: ");
    list2 = delete_pvalue(list2);
    print_list(list2);

    // Utilizzo della funzione increasing
    printf("La lista 1 senza valori in ordine crescente: ");
    list1 = increasing(list1, list1 -> value - 1);
    print_list(list1);

    // Utilizzo della funzione length_list
    printf("La lunghezza della lista 3 è: %i\n", length_list(list3));

    // Utilizzo della funzione sum_list
    printf("La somma gli elementi della lista 1 è: %i\n", sum_list(list1));

    // Utilizzo della funzione max_list
    printf("Il valore massimo nella lista 3 è: %i\n", max_list(list3));

    // Utilizzo della funzione min_list
    printf("Il valore minimo nella lista 4 è: %i\n", min_list(list4));

    // Utilizzo della funzione get_firts
    printf("Il primo valore della lista 4 è: %i\n", get_first(list4));

    // Utilizzo della funzione get_last
    printf("L'ultimo valore della lista 4 è: %i\n", get_last(list4));

    // Utilizzo della funzione equals_list
    printf("Confronto lista 1 e lista 3: \n");
    if (equals_list(list1, list3)) {
        printf("Le liste sono uguali!\n");
    } else {
        printf("Le liste sono diverse!\n");
    }

    // Utilizzo della funzione increment_list
    printf("La lista 3 con i valori incrementati è: ");
    increment_list(list3);
    print_list(list3);

    // Utilizzo della funzione list_to_array
    for (i = 0; i < SIZE; i++) {
        list6 = insert_on_head(list6, i + 23);
    }
    printf("La lista 6 è: ");
    print_list(list6);
    printf("L'array è: ");
    for (i = 0; i < SIZE; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
    list_to_array(list6 , array, SIZE);
    printf("L'array ora è: ");
    for (i = 0; i < SIZE; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    // Utilizzo delle funzioni selection_sort ed exchange
    printf("La lista 1 è: ");
    print_list(list1);
    selection_sort(list1);
    printf("La lista ordinata è: ");
    print_list(list1);

    // Utilizzo delle funzione free_list
    /* free_list(list1);
     * free_list(list2);
     * free_list(list3);
     * free_list(list4);
     * free_list(list5);
     * free_list(list6);
     */

    // Utilizzo della funzione list_without_pn
    printf("La lista 4 senza numeri primi è: ");
    list4 = list_without_pn(list4);
    print_list(list4);

    // Utilizzo della funzione rotate_list
    printf("La lista 5 ruotata è: ");
    list5 = rotate_list(list5);
    print_list(list5);

    // Utilizzo della funzione media
    printf("La media dei valori della lista 6 è: %f\n", media(list6));

    // Utilizzo della funzione complete_list
    printf("Lista 1 con l'aggiunta dei valori mancanti: ");
    complete_list(list1);
    print_list(list1);

    // Utilizzo della funzione median
    printf("La mediana della lista 4 è: %i\n",
    	   median(list4, length_list(list4)));

    // Utlizzo della funzione ordered_list
    if (ordered_list(list4)) {
    	printf("Gli elementi nella lista 4 sono fra loro in ordine.\n");
    } else {
    	printf("Gli elementi nella lista 4 non sono fra loro in ordine.\n");
    }

    // Utilizzo della funzione calculate_sublist
    printf("La sottolista (5) partendo dalla posizione 3 è: ");
    list5 = calculate_sublist(list5, 3);
    print_list(list5);

    // Utilizzo della funzione only_double
    printf("La lista con solo i valori doppi di lista 1: ");
    list1 = only_double(list1);
    print_list(list1);

    // Utilizzo della funzione even_odd
    printf("Relativo alla lista 5: \n");
    print_even_odd(list5);

    // Utilizzo della funzione delete_last_element
    printf("La lista 6 senza l'ultimo elemento è: ");
    delete_last_element(list6);
    print_list(list6);

    // Utilizzo della funzione add_list
    printf("La lista 1 sommata per se stessa: ");
    list1 = add_list(list1, list1);
    print_list(list1);

    // Utilizzo della funzione sub_list
    printf("La lista 2 sottratta per se stessa: ");
    list2 = sub_list(list2, list2);
    print_list(list2);

    // Utilizzo della funzione mul_list
    printf("La lista 3 moltiplicata per se stessa: ");
    list3 = add_list(list3, list3);
    print_list(list3);

    // Utilizzo della funzione div_list
    printf("La lista 4 divisa per se stessa: ");
    list4 = add_list(list4, list4);
    print_list(list4);
}
