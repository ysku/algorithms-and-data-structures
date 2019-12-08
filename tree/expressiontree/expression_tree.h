#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

typedef struct binary_tree_node_tag binary_tree_node;

struct binary_tree_node_tag {
    char value;
    binary_tree_node *left;
    binary_tree_node *right;
};

binary_tree_node *create_node(char value);

binary_tree_node *build_expr_tree(char postfix_expr[], int size);

#endif
