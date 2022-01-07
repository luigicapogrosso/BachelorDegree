/*
 * A userspace imitation of Linux kernel's Red-Black Tree.
 * Programmed by Luigi Capogrosso.
 */

// =============================================================================
#ifndef RBT_H
#define RBT_H
// =============================================================================
struct node_t
{
    int data;
    char color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
};
// =============================================================================
struct node_t *insert(struct node_t *root, int data);
// =============================================================================
void insert_fixup(struct node_t **root, struct node_t **z);
// =============================================================================
void left_rotate(struct node_t **root, struct node_t **x);
// =============================================================================
void right_rotate(struct node_t **root, struct node_t **x);
// =============================================================================
struct node_t *delete(struct node_t *root, struct node_t *z);
// =============================================================================
void delete_fixup(struct node_t **root, struct node_t **x);
// =============================================================================
void transplat(struct node_t **root, struct node_t **u, struct node_t **v);
// =============================================================================
void preorder(struct node_t *root);
// =============================================================================
struct node_t *tree_minimum(struct node_t *root);
// =============================================================================
struct node_t *bst_search(struct node_t *root, int x);
// =============================================================================
int find_minimum(struct node_t *root);
// =============================================================================
#endif
