#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

binary_search_tree_node *create_binary_search_tree_node(int value) {
    binary_search_tree_node *node = malloc(sizeof(binary_search_tree_node));
    if (!node) {
        printf("memory error!!\n");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

binary_search_tree *create_binary_search_tree() {
    binary_search_tree *bstree = malloc(sizeof(binary_search_tree));
    if (!bstree) {
        printf("memory error!!\n");
        return NULL;
    }
    bstree->root = NULL;
    return bstree;
}

binary_search_tree_node *find(binary_search_tree *bstree, int value) {
    binary_search_tree_node *root = bstree->root;
    if (!root) {
        printf("empty tree!!\n");
        return NULL;
    }
    while (1) {
        if (root->value == value) {
            return root;
        } else if (root->value > value) {
            if (root->left == NULL) goto not_found;
            root = root->left;
        } else {
            if (root->right == NULL) goto not_found;
            root = root->right;
        }
    }
not_found:
    printf("%d not found!!\n", value);
    return NULL;
}

binary_search_tree_node *insert(binary_search_tree **bstree, int value) {
    binary_search_tree_node *root = (*bstree)->root;
    binary_search_tree_node *new_node = create_binary_search_tree_node(value);
    if (!root) {
        (*bstree)->root = new_node;
        return new_node;
    }
    while (1) {
        if (root->value == new_node->value) {
            printf("already exist!!\n");
            return NULL;
        } else if (root->value > value) {
            if (root->left == NULL) {
                root->left = new_node;
                return new_node;
            }
            root = root->left;
        } else {
            if (root->right == NULL) {
                root->right = new_node;
                return new_node;
            }
            root = root->right;
        }
    }
}
