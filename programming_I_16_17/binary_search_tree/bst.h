/*
 * A userspace imitation of Linux kernel's Binary Search Tree - BST.
 * Programmed by Luigi Capogrosso.
 */

// =============================================================================
#ifndef BST_H
#define BST_H

#include <stdbool.h>
// =============================================================================
struct node_t
{
    int key;
    struct node_t *left;
    struct node_t *right;
};
// =============================================================================
// A utility function for find the minimum key in BST
int find_minimum(struct node_t *root);
// =============================================================================
// A utility function for find the maximum key in BST
int find_maximum(struct node_t *root);
// =============================================================================
// A utility function for check if a key is in the BST
bool find_value(struct node_t *root, int data);
// =============================================================================
/*
 * Given a non-empty binary search tree, return the node with minimum
 * key value found in that tree
 */
struct node_t *tree_minimum(struct node_t *root);
// =============================================================================
// A utility function to insert a new node with given key in BST
struct node_t *insert(struct node_t *root, int data);
// =============================================================================
/*
 * Given a binary search tree and a key, this function deletes the key
 * and returns the new root
 */
struct node_t *delete_node(struct node_t *root, int data);
// =============================================================================
// A utility function to do inorder traversal of BST
void inorder(struct node_t *root);
// =============================================================================
// A utility function to do preorder traversal of BST
void preorder(struct node_t *root);
// =============================================================================
#endif
