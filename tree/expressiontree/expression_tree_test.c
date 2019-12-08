#include <stdio.h>
#include <assert.h>
#include "expression_tree.h"

void test_expression_tree() {
    printf("[test] expression tree started\n");
    // A B C * + D /
    char expression[] = "A B C * + D /";
    int size = sizeof(expression) / sizeof(char);
    binary_tree_node *root = build_expr_tree(expression, size);

    assert( root->value == '/' );
    assert( root->left->value == '+' );
    assert( root->right->value == 'D' );
    assert( root->left->left->value == 'A' );
    assert( root->left->right->value == '*' );
    assert( root->left->right->left->value == 'B' );
    assert( root->left->right->right->value == 'C' );
    printf("[test] passed build_expr_tree\n");

    printf("[test] expression tree finished\n");
}

int main() {
    test_expression_tree();
    return 0;
}
