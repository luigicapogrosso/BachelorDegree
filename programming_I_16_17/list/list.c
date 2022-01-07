/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
// =============================================================================
struct list_t *construct(int num, struct list_t *node1)
{
    struct list_t *node2 = (struct list_t *) malloc(sizeof(struct list_t));

    node2 -> value = num;
    node2 -> next = node1;

    return node2;
}
// =============================================================================
struct list_t *insert_on_head(struct list_t *list, int num)
{
    if (list == NULL) {
        return construct(num, NULL);
    } else {
        return construct(num, list);
    }
}
// =============================================================================
struct list_t *insert_on_tail(struct list_t *list, int num)
{
    if (list == NULL) {
        return construct(num, NULL);
    } else {
        struct list_t *current = list;

        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = construct(num, (current -> next));

        return list;
    }
}
// =============================================================================
struct list_t *array_to_list(struct list_t *list, int array[], int length)
{
    int i;

    for (i = 0; i < length; i++) {
        list = insert_on_tail(list, array[i]);
    }

    return list;
}
// =============================================================================
struct list_t *delete_xvalue(struct list_t *list, int num)
{
    if (num == 0) {
        return list;
    } else {
        return delete_xvalue(list -> next, --num);
    }
}
// =============================================================================
struct list_t *merge_list(struct list_t *list1, struct list_t *list2)
{
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    } else if(list1 == NULL) {
        return list2;
    } else if(list2 == NULL) {
        return list1;
    } else {
        if (list1 -> value <= list2 -> value) {
            return construct(list1 -> value, merge_list(list1 -> next, list2));
        } else {
            return construct(list2 -> value, merge_list(list1, list2 -> next));
        }
    }
}
// =============================================================================
struct list_t *first_equal(struct list_t *list)
{
    if (list == NULL) {
        return NULL;
    } else {
        if (list -> value % 2 == 0) {
            return list;
        } else {
            return first_equal(list -> next);
        }
    }
}
// =============================================================================
struct list_t *minimun_equal(struct list_t *list)
{
    if (list == NULL) {
        return NULL;
    } else {
        if (list -> value % 2 == 0) {
            return list;
        } else {
            return minimun_equal(list -> next);
        }
    }
}
// =============================================================================
struct list_t *read_list()
{
    int val = 1;
    struct list_t *return_list = NULL;

    while (val != 0) {
        printf("? ");
        scanf("%i", &val);
        if (val != 0) {
            return_list = insert_on_head(return_list, val);
        }
    }

    return return_list;
}
// =============================================================================
struct list_t *delete_nvalue(struct list_t *list)
{
    struct list_t *current = list;
    struct list_t *return_list = NULL;

    while (current != NULL) {
        if ((current -> value) > 0) {
            return_list = insert_on_head(return_list, (current -> value));
        }
        current = current -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *delete_pvalue(struct list_t *list)
{
    struct list_t *current = list;
    struct list_t *return_list = NULL;

    while (current != NULL) {
        if ((current -> value) < 0) {
            return_list = insert_on_head(return_list, (current -> value));
        }
        current = current -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *increasing(struct list_t *list, int num)
{
    if (list == NULL) {
        return NULL;
    } else {
        if (list -> value > num) {
            return construct(list -> value,
                             increasing(list -> next, list -> value));
        } else {
            return increasing(list -> next, num);
        }
    }
}
// =============================================================================
int length_list(struct list_t *list)
{
    if (list == NULL) {
        return 0;
    } else {
        return 1 + length_list(list -> next);
    }
}
// =============================================================================
int sum_list(struct list_t *list)
{
    if (list -> next == NULL) {
        return list -> value;
    } else {
        return list -> value + sum_list(list -> next);
    }
}
// =============================================================================
int max_list(struct list_t *list)
{
    int max = list -> value;
    struct list_t *current = list;

    while (current != NULL) {
        if (current -> value > max) {
            max = current -> value;
        }
        current = current -> next;
    }

    return max;
}
// =============================================================================
int min_list(struct list_t *list)
{
    int min = list -> value;
    struct list_t *current = list;

    while (current != NULL) {
        if (current -> value < min) {
            min = current -> value;
        }
        current = current -> next;
    }

    return min;
}
// =============================================================================
int get_first(struct list_t *list)
{
    return list -> value;
}
// =============================================================================
int get_last(struct list_t *list)
{
    if (list -> next == NULL) {
        return list -> value;
    } else {
        return get_last(list -> next);
    }
}
// =============================================================================
bool equals_list(struct list_t *list1, struct list_t *list2)
{
    if (list1 -> next == NULL && list2 -> next == NULL) {
        return true;
    } else if(list1 -> next == NULL && list2 -> next != NULL) {
        return false;
    } else if(list1 -> next != NULL && list2 -> next == NULL) {
        return false;
    } else {
        return list1 -> value == list2 -> value &&
               equals_list(list1 -> next, list2 -> next);
    }
}
// =============================================================================
void increment_list(struct list_t *list)
{
    if (list != NULL) {
        list -> value += 1;
        return increment_list(list -> next);
    }
}
// =============================================================================
void list_to_array(struct list_t *list, int array[], int length)
{
    int i = 0;
    struct list_t *current = list;

    while (current != NULL) {
        array[i] = current -> value;
        current = current -> next;
        i++;
    }
}
// =============================================================================
void print_list(struct list_t *list)
{
    if (list == NULL) {
        printf("La lista è vuota!\n");
    } else {
        struct list_t *current = list;

        printf("[");

        while (current -> next != NULL) {
            printf("%i ", current -> value);
            current = current -> next;
        }

        printf("%i]\n", current -> value);
    }
}
// =============================================================================
void free_list(struct list_t *list)
{
    struct list_t *current = list;

    while (current != NULL) {
        free(current);
        current = current -> next;
    }
}
// =============================================================================
void selection_sort(struct list_t *list)
{
    struct list_t *current;

    while (list != NULL) {
        current = list -> next;

        while (current != NULL) {
            if (list -> value > current -> value) {
                exchange(&(list -> value), &(current -> value));
            }
            current = current -> next;
        }

        list = list -> next;
    }
}
// =============================================================================
void exchange(int *n1, int *n2)
{
    int n;
    n = *n1;
    *n1 = *n2;
    *n2 = n;
}
// =============================================================================
bool not_first(int num)
{
    int i;
    bool not_first = false;

    for (i = 2; i < num; i++) {
        if ((num % i) == 0) {
            not_first = true;
        }
    }

    return not_first;
}
// =============================================================================
struct list_t *list_without_pn(struct list_t *list)
{
    struct list_t *return_list = NULL;
    struct list_t *current = list;

    while (current -> next != NULL) {
        if (not_first(current -> value)) {
            return_list = insert_on_tail(return_list, current -> value);
        }
        current = current -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *rotate_list(struct list_t *list)
{
    int i;
    struct list_t *return_list = NULL;
    struct list_t *current = list;

    while (current != NULL) {
        return_list = insert_on_head(return_list, current -> value);
        current = current -> next;
    }

    return return_list;
}
// =============================================================================
float media(struct list_t *list)
{
    int l = length_list(list);
    float tot = 0;
    struct list_t *current = list;

    while (current != NULL) {
        tot += current -> value;
        current = current -> next;
    }

    return tot / l;
}
// =============================================================================
void complete_list(struct list_t *list)
{
    struct list_t *current;

    while (list -> next != NULL) {
        if (list -> next -> value - list -> value != 1) {
            current = (struct list_t *) malloc(sizeof(struct list_t));
            current -> value = (list -> value) + 1;
            current -> next = list -> next;
            list -> next = current;
        } else {
            list = list -> next;
        }
    }
}// =============================================================================
int median(struct list_t *list, int l)
{
    int i = 0;
    struct list_t *current = list;

    while (current -> next != NULL) {
        if (i == (l / 2)) {
            return current -> value;
        }
        i++;
        current = current -> next;
    }
}
// =============================================================================
bool ordered_list(struct list_t *list)
{
    while (list -> next != NULL) {
        if (list -> next -> value - list -> value != 1) {
            return false;
        }
        list = list -> next;
    }

    return true;
}
// =============================================================================
struct list_t *calculate_sublist(struct list_t *list, int num)
{
    int i;
    struct list_t *current = list;
    struct list_t *return_list = NULL;

    for (i = 1; i < num; i++) {
        current = current -> next;
    }

    while (current != NULL) {
        return_list = insert_on_tail(return_list, current -> value);
        current = current -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *only_double(struct list_t *list)
{
    int n_of_occurence;
    struct list_t *current;
    struct list_t *return_list = NULL;

    while (list != NULL) {
        n_of_occurence = 0;
        current = list -> next;

        while (current != NULL) {
            if (list -> value == current -> value) {
                n_of_occurence++;
            }
            current = current -> next;
        }

        if (n_of_occurence == 1) {
            return_list = insert_on_tail(return_list, list -> value);
        }

        list = list -> next;
    }

    return return_list;
}
// =============================================================================
void print_even_odd(struct list_t *list)
{
    struct list_t *even = NULL;
    struct list_t *odd = NULL;
    struct list_t *current = list;

    while (current != NULL) {
        if (current -> value % 2 == 0) {
            even = insert_on_tail(even, current -> value);
        } else {
            odd = insert_on_tail(odd, current -> value);
        }
        current = current -> next;
    }

    printf("La lista con solo i valori pari: ");
    print_list(even);

    printf("La lista con solo i valori dispari: ");
    print_list(odd);
}
// =============================================================================
void delete_last_element(struct list_t *list)
{
    while (list -> next -> next != NULL) {
        list = list -> next;
    }

    free(list -> next);
    list -> next = NULL;
}
// =============================================================================
struct list_t *mul_list(struct list_t *l1, struct list_t *l2)
{
    struct list_t *return_list;

    while (l1 != NULL) {
        return_list = insert_on_tail(return_list, l1 -> value * l2 -> value);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *add_list(struct list_t *l1, struct list_t *l2)
{
    struct list_t *return_list;

    while (l1 != NULL) {
        return_list = insert_on_tail(return_list, l1 -> value + l2 -> value);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *div_list(struct list_t *l1, struct list_t *l2)
{
    struct list_t *return_list;

    while (l1 != NULL) {
        return_list = insert_on_tail(return_list, l1 -> value / l2 -> value);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    return return_list;
}
// =============================================================================
struct list_t *sub_list(struct list_t *l1, struct list_t *l2)
{
    struct list_t *return_list;

    while (l1 != NULL) {
        return_list = insert_on_tail(return_list, l1 -> value - l2 -> value);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    return return_list;
}
