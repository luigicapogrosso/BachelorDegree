/*
 * A userspace imitation of Linux kernel's Red-Black Tree.
 * Programmed by Luigi Capogrosso.
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
// =============================================================================
int main(int argc, char const *argv[])
{
    int i;
    struct node_t *rbt = NULL;

    rbt = insert(rbt, 10);
    rbt = insert(rbt, 23);
    rbt = insert(rbt, 38);
    rbt = insert(rbt, 49);
    rbt = insert(rbt, 3);
    rbt = insert(rbt, 67);
    rbt = insert(rbt, 71);
    rbt = insert(rbt, 24);

    printf("Preorder\n");
    preorder(rbt);

    for (i = 0; i < 8; i++)
    {
        // Trovo il valore più piccolo.
        int min = find_minimum(rbt);

        // Acquisisco l'albero dove si trova il valore più piccolo.
        struct node_t *x = bst_search(rbt, min);

        // Rimuovo il nodo dall'albero.
        rbt = delete(rbt, x);

        // Stampa del risulato.
        printf("\nAfter deleting %d\n", min);
        printf("\nPreorder\n");
        preorder(rbt);
        printf("\n");
    }

    return 0;
}
