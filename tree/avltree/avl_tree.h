#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdio.h>

typedef struct avl_tree_node_tag avl_tree_node;

struct avl_tree_node_tag {
    int value;
    int height;
    avl_tree_node *left;
    avl_tree_node *right;
};

avl_tree_node *create_avl_tree_node(int value);

typedef struct {
    avl_tree_node *root;
    int height;
} avl_tree;

avl_tree *create_avl_tree();

void insert(avl_tree *tree, int value);

void display_tree(avl_tree *tree);

#endif
