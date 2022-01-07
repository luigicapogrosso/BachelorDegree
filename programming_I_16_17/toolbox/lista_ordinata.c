/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Funzioni generiche per operare su una lista ordinata.
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// =============================================================================
struct node_t {
    int value;
    struct node_t *next;
};

struct list_t {
    struct node_t *head;
};
// =============================================================================
struct list_t *new_list();
void insert_into_list(struct list_t *list, int value);
void print_list(struct list_t *list);
bool contains(struct list_t *list, int value);
void remove_from_list(struct list_t *list, int value);
void empty_list(struct list_t *list);
void free_list(struct list_t *list);
// =============================================================================
int main()
{
    int i;
    struct list_t *list = new_list();

    insert_into_list(list, 1);
    insert_into_list(list, 2);
    insert_into_list(list, 3);
    insert_into_list(list, 5);
    insert_into_list(list, 20);
    insert_into_list(list, 19);
    insert_into_list(list, 98);
    insert_into_list(list, 13);
    insert_into_list(list, 12);
    print_list(list);
    printf("\n");

    if (contains(list, 5)) {
        printf("Il numero 5 è in lista!\n");
    } else {
        printf("Il numero 5 non è in lista!\n");
    }

    if (contains(list, 50)) {
        printf("Il numero 50 è in lista!\n");
    } else {
        printf("Il numero 50 non è in lista!\n");
    }

    remove_from_list(list, 5);
    print_list(list);
    printf("\n");
    if (contains(list, 5)) {
        printf("Il numero 5 è in lista!\n");
    } else {
        printf("Il numero 5 non è in lista!\n");
    }

    empty_list(list);
    print_list(list);
    printf("\n");

    free_list(list);
}
// =============================================================================
struct list_t *new_list()
{
    struct list_t *list = (struct list_t *) malloc(sizeof(struct list_t));

    list -> head = NULL;

    return list;
}
// =============================================================================
void insert_into_list(struct list_t *list, int value)
{
    struct node_t *node = (struct node_t *) malloc(sizeof(struct node_t));

    node -> value = value;
    // Inserimento in testa
    if (list -> head == NULL) {
        node -> next = list -> head;
        list -> head = node;
    // Inserimento in posizione corretta
    } else {
        struct node_t *current = list -> head;
        struct node_t *previous = NULL;
        while (current != NULL) {
            if (current -> value >= value) {
                node -> next = current;
                if (previous != NULL) {
                    previous -> next = node;
                }
                return;
            }
            previous = current;
            current = current -> next;
        }
        // Inserimento in coda
        previous -> next = node;
        node -> next = NULL;
    }
}
// =============================================================================
void print_list(struct list_t *list)
{
    if (list -> head == NULL) {
        printf("La lista è vuota!");
    }
    struct node_t *current = list -> head;

    while (current != NULL) {
        printf("%i ", current -> value);
        current = current -> next;
    }
}
// =============================================================================
bool contains(struct list_t *list, int value)
{
    struct node_t *current = list -> head;

    while (current != NULL) {
        if (current -> value == value) {
            return true;
        } else if(current -> value > value) {
            return false;
        }
        current = current -> next;
    }
    return false;
}
// =============================================================================
void remove_from_list(struct list_t *list, int value)
{
    struct node_t *current = list -> head;
    struct node_t *previous = NULL;

    while (current != NULL) {
        if (current -> value == value) {
            previous -> next = current -> next;
            free(current);
            return;
        }
        previous = current;
        current = current -> next;
    }
}
// =============================================================================
void empty_list(struct list_t *list)
{
    struct node_t *current = list -> head;
    struct node_t *previous = NULL;

    while (current != NULL) {
        if (previous != NULL) {
            free(previous);
        }
        previous = current;
        current = current -> next;
    }
    if (previous != NULL) {
        free(previous);
    }
    list -> head = NULL;
}
// =============================================================================
void free_list(struct list_t *list)
{
	empty_list(list);
	free(list);
}
