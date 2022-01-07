/*
 * A userspace imitation of Linux kernel's Binary Search Tree - BST.
 * Programmed by Luigi Capogrosso.
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
// =============================================================================
int main(int argc, char const *argv[])
{
    /*
     * Create the following BST:
     *          50
     *       /     \
     *      30      70
     *     /  \    /  \
     *  20   40  60   80
     */

    struct node_t *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = delete_node(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = delete_node(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = delete_node(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\n");

    return 0;
}
