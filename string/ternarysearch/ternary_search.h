#ifndef TERNARY_SEARCH_H
#define TERNARY_SEARCH_H

#include <stdio.h>
#include <stdbool.h>

typedef struct tst_node_tag tst_node;

struct tst_node_tag {
    char character;
    bool is_end_of_word;
    tst_node *left;
    tst_node *eq;
    tst_node *right;
};

tst_node *create_tst_node();

void insert(tst_node *root, char *word);

bool search(tst_node *root, char *word);

void display_tst_node(tst_node *node);

void display_all_words(tst_node *root);

#endif
