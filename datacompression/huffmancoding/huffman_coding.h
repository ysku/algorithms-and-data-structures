#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <stdint.h>
#include <stddef.h>

typedef struct node_tag node;

struct node_tag {
    char character;
    size_t repetition;
    char *code;
    node *left;
    node *right;
};

node *create_node(char character);

void insert_node(node **root, node *entry);

char *huffman_coding(char *s);

#endif
