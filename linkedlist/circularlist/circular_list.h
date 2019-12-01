#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <stdio.h>

typedef struct circular_list_node_tag circular_list_node;

struct circular_list_node_tag {
    circular_list_node *next;
    int value;
};

circular_list_node *new_circular_list_node(int value);

void insert(circular_list_node *root, int value);

int length(circular_list_node *root);

circular_list_node *get(circular_list_node *root, int i);

circular_list_node *delete(circular_list_node *root, int i);

circular_list_node *pop(circular_list_node **root);

#endif
