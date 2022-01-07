/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * Funzioni generiche per operare su una lista non ordinata.
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
void insert_on_head(struct list_t *list, int value);
void insert_on_tail(struct list_t *list, int value);
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
    print_list(list);
    printf("\n");

    for (i = 0; i < 10; i++) {
        insert_on_head(list, i);
    }
    print_list(list);
    printf("\n");

    for (i = 10; i < 20; i++) {
        insert_on_tail(list, i);
    }
    print_list(list);
    printf("\n");

    if (contains(list, 5)) {
        printf("Il numero 5 è in lista!\n");
    } else {
        printf("Il numero 5 non è in lista!\n");
    }

    // Verifica della presenza del numero 50
    if (contains(list, 50)) {
        printf("Il numero 50 è in lista!\n");
    } else {
        printf("Il numero 50 non è in lista!\n");
    }

    // Rimozione, e seguente verifica della presenza del numero 5
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
void insert_on_head(struct list_t *list, int value)
{
    struct node_t *node = (struct node_t *) malloc(sizeof(struct node_t));

    node -> value = value;
    node -> next = list -> head;
    list -> head = node;
}
// =============================================================================
void insert_on_tail(struct list_t *list, int value)
{
    if (list -> head == NULL) {
        insert_on_head(list, value);
    } else {
        struct node_t *current = list -> head;

        while (current -> next != NULL) {
            current = current -> next;
        }
        struct node_t *node = (struct node_t *) malloc(sizeof(struct node_t));

        node -> value = value;
        node -> next = NULL;
        current -> next = node;
    }
}
// =============================================================================
void print_list(struct list_t *list)
{
    if (list -> head == NULL) {
        printf("La lista è vuota!\n");
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
            if (current == list -> head) {
                list -> head = current -> next;
                free(current);
            } else {
                previous -> next = current -> next;
                free(current);
            }
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
