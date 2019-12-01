#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct linked_list_node_tag linked_list_node;

struct linked_list_node_tag {
    linked_list_node *next;
    int value;
};

linked_list_node *new_linked_list_node(int value);

void insert(linked_list_node *l, int value);

int length(linked_list_node *l);

linked_list_node *get(linked_list_node *l, int i);

linked_list_node *delete_node(linked_list_node *l, int i);

linked_list_node *pop(linked_list_node **l);

#endif /* LINKED_LIST_H */
