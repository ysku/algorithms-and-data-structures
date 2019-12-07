#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h>

typedef struct binary_tree_node_tag binary_tree_node;

struct binary_tree_node_tag {
    int value;
    binary_tree_node *left;
    binary_tree_node *right;
};

binary_tree_node *create_node(int value);

void pre_order(binary_tree_node *root);

void in_order(binary_tree_node *root);

void post_order(binary_tree_node *root);

#endif
