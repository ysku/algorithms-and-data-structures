#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct trie_node_tag trie_node;

struct trie_node_tag {
    char character;
    bool is_end_of_word;
    trie_node *children[ALPHABET_SIZE];
};

trie_node *create_trie_node();

void insert(trie_node *root, char *word);

bool search(trie_node *root, char *word);

void traverse(trie_node *root);

#endif
