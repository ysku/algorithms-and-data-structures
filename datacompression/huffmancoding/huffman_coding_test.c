#include "huffman_coding.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

void test_insert_node() {
    printf("[test] test_insert_node started!!\n");

    node *root = create_node('\0');

    node *node1 = create_node('b');
    node1->repetition = 2;

    insert_node(&root, node1);

    assert( root->repetition == 2 );
    assert( root->left->character == 'b' );
    assert( root->left->repetition == 2 );

    node *node2 = create_node('c');
    node2->repetition = 7;

    insert_node(&root, node2);

    assert( root->repetition == 9 );
    assert( root->left->character == 'b' );
    assert( root->left->repetition == 2 );
    assert( root->right->character == 'c' );
    assert( root->right->repetition == 7 );

    node *node3 = create_node('a');
    node3->repetition = 12;

    insert_node(&root, node3);

    assert( root->character == '\0' );
    assert( root->repetition == 21 );
    assert( root->left->character == '\0' );
    assert( root->left->repetition == 9 );
    assert( root->right->character == 'a' );
    assert( root->right->repetition == 12 );
    assert( root->left->left->character == 'b' );
    assert( root->left->left->repetition == 2 );
    assert( root->left->right->character == 'c' );
    assert( root->left->right->repetition == 7 );

    node *node4 = create_node('d');
    node4->repetition = 13;

    insert_node(&root, node4);

    assert( root->character == '\0' );
    assert( root->repetition == 34 );
    assert( root->left->character == '\0' );
    assert( root->left->repetition == 21 );
    assert( root->right->character == 'd' );
    assert( root->right->repetition == 13 );
    assert( root->left->left->character == '\0' );
    assert( root->left->left->repetition == 9 );
    assert( root->left->right->character == 'a' );
    assert( root->left->right->repetition == 12 );
    assert( root->left->left->left->character == 'b' );
    assert( root->left->left->left->repetition == 2 );
    assert( root->left->left->right->character == 'c' );
    assert( root->left->left->right->repetition == 7 );

    printf("[test] test_insert_node finished!!\n");
}

void test_huffman_coding() {
    printf("[test] test_huffman_coding started!!\n");

    char given[] = "ADBCBABCBBCE";
    // A : 2
    // B : 5
    // C : 3
    // D : 1
    // E : 1
    huffman_coding(given);

    printf("[test] test_huffman_coding finished!!\n");
}

int main() {
    test_insert_node();

    test_huffman_coding();

    return 0;
}
