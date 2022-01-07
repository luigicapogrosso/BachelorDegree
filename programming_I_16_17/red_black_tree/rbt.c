/*
 * A userspace imitation of Linux kernel's Red-Black Tree.
 * Programmed by Luigi Capogrosso.
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
// =============================================================================
struct node_t *insert(struct node_t *root, int data)
{
    struct node_t *z = (struct node_t *) malloc(sizeof(struct node_t));
    z->data = data;
    z->color = 'R';
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    struct node_t *y = NULL;
    struct node_t *x = root;

    while (x != NULL)
    {
        y = x;

        if (z->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->parent = y;

    if (y == NULL)
    {
        root = z;
    }
    else if (z->data < y->data)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }

    insert_fixup(&root, &z);

    return root;
}
// =============================================================================
void insert_fixup(struct node_t **root, struct node_t **z)
{
    struct node_t *grandparent = NULL;
    struct node_t *parentpt = NULL;

    while (((*z) != (*root))        &&
           ((*z)->color != 'B')     &&
           ((*z)->parent->color == 'R'))
    {

        parentpt = (*z)->parent;
        grandparent = (*z)->parent->parent;

        if (parentpt == grandparent->left)
        {
            struct node_t *uncle = grandparent->right;

            if (uncle != NULL && uncle->color == 'R')
            {
                grandparent->color = 'R';
                parentpt->color = 'B';
                uncle->color = 'B';
                *z = grandparent;
            }
            else
            {
                if ((*z) == parentpt->right)
                {
                    left_rotate(root, &parentpt);
                    (*z) = parentpt;
                    parentpt = (*z)->parent;
                }
                right_rotate(root, &grandparent);
                parentpt->color = 'B';
                grandparent->color = 'R';
                (*z) = parentpt;
            }
        }
        else
        {
            struct node_t *uncle = grandparent->left;

            if (uncle != NULL && uncle->color == 'R')
            {
                grandparent->color = 'R';
                parentpt->color = 'B';
                uncle->color = 'B';
                (*z) = grandparent;
            }
            else
            {
                if((*z) == parentpt->left)
                {
                    right_rotate(root, &parentpt);
                    (*z) = parentpt;
                    parentpt = (*z)->parent;
                }
                left_rotate(root, &grandparent);
                parentpt->color = 'B';
                grandparent->color = 'R';
                (*z) = parentpt;
            }
        }
    }
    (*root)->color = 'B';
}
// =============================================================================
void left_rotate(struct node_t **root, struct node_t **x)
{
    struct node_t *y = (*x)->right;
    (*x)->right = y->left;

    if (y->left != NULL)
    {
        y->left->parent = *x;
    }
    y->parent = (*x)->parent;

    if ((*x)->parent == NULL)
    {
        *root = y;
    }
    else if (*x == (*x)->parent->left)
    {
        (*x)->parent->left = y;
    }
    else
    {
        (*x)->parent->right = y;
    }

    y->left = *x;
    (*x)->parent = y;
}
// =============================================================================
void right_rotate(struct node_t **root, struct node_t **x)
{
    struct node_t *y = (*x)->left;
    (*x)->left = y->right;

    if (y->right != NULL)
    {
        y->right->parent = *x;
    }
    y->parent = (*x)->parent;

    if ((*x)->parent == NULL)
    {
        *root = y;
    }
    else if ((*x) == (*x)->parent->left)
    {
        (*x)->parent->left = y;
    }
    else
    {
        (*x)->parent->right = y;
    }

    y->right = *x;
    (*x)->parent = y;
}
// =============================================================================
void preorder(struct node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// =============================================================================
struct node_t *delete(struct node_t *root, struct node_t *z)
{
    if (root->left == NULL && root->right == NULL && root->parent == NULL)
    {
        return NULL;
    }

    struct node_t *y = z;
    char yoc;
    yoc = z->color;

    struct node_t *x;

    if (z->left == NULL)
    {
        x = z->right;
        transplat(&root, &z, &(z->right));
    }
    else if (z->right == NULL)
    {
        x = z->left;
        transplat(&root, &z, &(z->left));
    }
    else
    {
        y = tree_minimum(z->right);
        yoc = y->color;
        x = y->right;

        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplat(&root, &y, &(y->right));
            y->right = z->right;
            y->right->parent = y;
        }

        transplat(&root, &z, &y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (yoc == 'B')
    {
        delete_fixup(&root, &x);
    }

    return root;
}
// =============================================================================
void delete_fixup(struct node_t **root, struct node_t **x)
{
    if (x == NULL || (*x) == NULL)
    {
        return;
    }

    while (((*x) != *root) && (*x)->color == 'B')
    {
        if ((*x) == (*x)->parent->left)
        {
            struct node_t *w = (*x)->parent->right;

            if (w->color == 'R')
            {
                w->color = 'B';
                (*x)->parent->color = 'B';
                left_rotate(root, &((*x)->parent));
                w = (*x)->parent->right;
            }

            if (w->left->color == 'B' && w->right->color == 'B')
            {
                w->color = 'R';
                (*x) = (*x)->parent;
            }
            else
            {
                if (w->right->color == 'B')
                {
                    w->left->color = 'B';
                    w->color = 'R';
                    right_rotate(root, &w);
                    w = (*x)->parent->right;
                }

                w->color = (*x)->parent->color;
                (*x)->parent->color = 'B';
                w->right->color = 'B';
                left_rotate(root, &((*x)->parent));
                (*x) = *root;
            }
        }
        else
        {
            struct node_t *w = (*x)->parent->left;

            if (w->color == 'R')
            {
                w->color = 'B';
                (*x)->parent->color = 'B';
                right_rotate(root, &((*x)->parent));
                w = (*x)->parent->left;
            }

            if (w->right->color=='B' && w->left->color == 'B')
            {
                w->color = 'R';
                (*x) = (*x)->parent;
            }
            else
            {
                if (w->left->color == 'B')
                {
                    w->right->color = 'B';
                    w->color = 'R';
                    left_rotate(root, &w);
                    w = (*x)->parent->left;
                }

                w->color = (*x)->parent->color;
                (*x)->parent->color = 'B';
                w->left->color = 'B';
                right_rotate(root, &((*x)->parent));
                (*x) = *root;
            }
        }
    }
    (*x)->color = 'B';
}
// =============================================================================
void transplat(struct node_t **root, struct node_t **u, struct node_t **v)
{
    if ((*u)->parent == NULL)
    {
        *root = *v;
    }
    else if ((*u) == (*u)->parent->left)
    {
        (*u)->parent->left = *v;
    }
    else
    {
        (*u)->parent->right = *v;
    }
    if ((*v) != NULL)
    {
        (*v)->parent = (*u)->parent;
    }
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
struct node_t *bst_search(struct node_t *root, int x)
{
    if (root == NULL || root->data == x)
    {
        return root;
    }
    if (root->data > x)
    {
       return  bst_search(root->left, x);
    }
    else
    {
        return bst_search(root->right, x);
    }
}
// =============================================================================
int find_minimum(struct node_t *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}
