#include <stdio.h>
#include "binary_tree.h"

void test_binary_tree() {
    printf("[test] binary tree started\n");
    // create binary tree
    binary_tree_node *root = create_node(1);
    root->left = create_node(2);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right = create_node(3);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
    printf("[test] pass create binary tree node\n");

    // 1 2 4 5 3 6 7
    pre_order(root);
    printf("[test] pass pre order\n");

    // 4 2 5 1 6 3 7
    in_order(root);
    printf("[test] pass in order\n");

    // 4 5 2 6 7 3 1
    post_order(root);
    printf("[test] pass post order\n");

    printf("[test] binary tree finished\n");
}

int main() {
    test_binary_tree();
    return 0;
}
