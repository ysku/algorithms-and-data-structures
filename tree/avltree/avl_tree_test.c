#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "avl_tree.h"

void test_single_rotate_left() {
    printf("[test] test single rotate left started\n");

    avl_tree *avltree = create_avl_tree();

    int numbers[] = {6, 5, 9, 3, 8, 7};
    int size = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < size; i++) {
        insert(avltree, numbers[i]);
    }

    display_tree(avltree);

    assert( avltree->root->value == 6 );
    assert( avltree->root->left->value == 5 );
    assert( avltree->root->left->left->value == 3 );
    assert( avltree->root->right->value == 8 );
    assert( avltree->root->right->left->value == 7 );
    assert( avltree->root->right->right->value == 9 );

    display_tree(avltree);

    printf("[test] test single rotate left finished\n");
}

void test_single_rotate_right() {
    printf("[test] test single rotate right started\n");

    avl_tree *avltree = create_avl_tree();

    int numbers[] = {8, 6, 15, 3, 19, 29};
    int size = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < size; i++) {
        insert(avltree, numbers[i]);
    }

    assert( avltree->root->value == 8 );
    assert( avltree->root->left->value == 6 );
    assert( avltree->root->left->left->value == 3 );
    assert( avltree->root->right->value == 19 );
    assert( avltree->root->right->left->value == 15 );
    assert( avltree->root->right->right->value == 29 );

    display_tree(avltree);

    printf("[test] test single rotate right finished\n");
}

void test_double_rotate_with_left() {
    printf("[test] test double rotate with left started\n");

    avl_tree *avltree = create_avl_tree();

    int numbers[] = {8, 5, 9, 3, 6, 7};
    int size = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < size; i++) {
        insert(avltree, numbers[i]);
    }

    display_tree(avltree);
    assert( avltree->root->value == 6 );
    assert( avltree->root->left->value == 5 );
    assert( avltree->root->left->left->value == 3 );
    assert( avltree->root->right->value == 8 );
    assert( avltree->root->right->left->value == 7 );
    assert( avltree->root->right->right->value == 9 );

    display_tree(avltree);

    printf("[test] test double rotate with left finished\n");
}

void test_double_rotate_with_right() {
    printf("[test] test double rotate with right started\n");

    avl_tree *avltree = create_avl_tree();

    int numbers[] = {4, 2, 7, 6, 8, 5};
    int size = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < size; i++) {
        insert(avltree, numbers[i]);
    }

    assert( avltree->root->value == 6 );
    assert( avltree->root->left->value == 4 );
    assert( avltree->root->left->left->value == 2 );
    assert( avltree->root->left->right->value == 5 );
    assert( avltree->root->right->value == 7 );
    assert( avltree->root->right->right->value == 8 );

    display_tree(avltree);

    printf("[test] test double rotate with right finished\n");
}

void test_avl_tree() {
    printf("[test] avl tree test started\n");

    test_single_rotate_left();

    test_single_rotate_right();

    test_double_rotate_with_left();

    test_double_rotate_with_right();

    printf("[test] avl tree test finished\n");
}

int main() {
    test_avl_tree();
    return 0;
}