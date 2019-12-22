#include <stdio.h>
#include <stdlib.h>
#include "ternary_search.h"

tst_node *create_tst_node() {
    tst_node *node = malloc(sizeof(tst_node));
    if (!node) {
        fprintf(stderr, "memory error!!\n");
        return NULL;
    }
    node->character = '\0';
    node->is_end_of_word = false;
    node->left = NULL;
    node->eq = NULL;
    node->right = NULL;
    return node;
}

void insert(tst_node *root, char *word) {
    size_t idx = 0;
    if (root->character == '\0') {
        root->character = word[idx];
    }
    while (word[idx] != '\0') {
        if (root->character == word[idx]) {
            if (root->eq == NULL) {
                tst_node *node = create_tst_node();
                node->character = word[idx];
                root->eq = node;
            }
            root = root->eq;
        } else if (root->character > word[idx]) {
            if (root->left == NULL) {
                tst_node *node = create_tst_node();
                node->character = word[idx];
                root->left = node;
            }
            root = root->left;
        } else {
            if (root->right == NULL) {
                tst_node *node = create_tst_node();
                node->character = word[idx];
                root->right = node;
            }
            root = root->right;
        }
        printf("%c", root->character);
        idx++;
    }
    root->is_end_of_word = true;
    printf("\n");
}

bool search(tst_node *root, char *word) {
    size_t idx = 0;
    while (word[idx] != '\0' && root != NULL) {
        if (root->character == word[idx]) {
            root = root->eq;
        } else if (root->character > word[idx]) {
            root = root->left;
        } else {
            root = root->right;
        }
        idx++;
    }
    if (root) {
        return root->is_end_of_word;
    }
    return false;
}

void display_tst_node(tst_node *node) {
    printf(" === tst node === \n");
    printf(" character : %c\n", node->character);
    if (node->left) {
        printf(" left : %c\n", node->left->character);
    }
    if (node->eq) {
        printf(" eq : %c\n", node->eq->character);
    }
    if (node->right) {
        printf(" right : %c\n", node->right->character);
    }
    printf(" is end of word : %s\n", node->is_end_of_word ? "true" : "false");
    printf(" ================ \n");
}

void display_all_words(tst_node *root) {
    // TODO:
}
