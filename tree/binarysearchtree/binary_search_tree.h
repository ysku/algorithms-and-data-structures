#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct binary_search_tree_node_tag binary_search_tree_node;

struct binary_search_tree_node_tag {
    int value;
    binary_search_tree_node *left;
    binary_search_tree_node *right;
};

binary_search_tree_node *create_binary_search_tree_node(int value);

typedef struct binary_search_tree {
    binary_search_tree_node *root;
} binary_search_tree;

binary_search_tree *create_binary_search_tree();

binary_search_tree_node *find(binary_search_tree *bstree, int value);

binary_search_tree_node *insert(binary_search_tree **bstree, int value);

#endif
