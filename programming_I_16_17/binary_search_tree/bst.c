/*
 * A userspace imitation of Linux kernel's Binary Search Tree - BST.
 * Programmed by Luigi Capogrosso.
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
// =============================================================================
int find_minimum(struct node_t *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->key;
}
// =============================================================================
int find_maximum(struct node_t *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->key;
}
// =============================================================================
bool find_value(struct node_t *root, int data)
{
    while (root != NULL && root->key != data)
    {
        if (data < root->key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (root == NULL)
    {
        return false;
    }

    return true;
}
// =============================================================================
struct node_t *tree_minimum(struct node_t *root)
{
    if (root->left == NULL)
    {
        return root;
    }

    return tree_minimum(root->left);
}
// =============================================================================
struct node_t *insert(struct node_t *root, int data)
{
    struct node_t *node = (struct node_t *) malloc(sizeof(struct node_t));
    node->key = data;
    node->left = NULL;
    node->right = NULL;

    struct node_t *y = NULL;
    struct node_t *x = root;

    while (x != NULL)
    {
        y = x;
        if (node->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    if (y == NULL)
    {
        return node;
    }
    else if (node->key < y->key)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    return root;
}
// =============================================================================
struct node_t *delete_node(struct node_t *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->key)
    {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = delete_node(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node_t *temp = root->left;
            free(root);
            return temp;
        }

        struct node_t *temp = tree_minimum(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }

    return root;
}
// =============================================================================
void inorder(struct node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
// =============================================================================
void preorder(struct node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}
