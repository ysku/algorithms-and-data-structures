#ifndef STRUCTURES_SET_H
#define STRUCTURES_SET_H

typedef struct node_tag node;

struct node_tag {
    int value;
    node *next;
};

node *create_node(int value);

typedef struct {
    int count;
    node *next;
} set;

set *create_set();

int length(set *s);

void add_value(set *s, int value);

int remove_value(set *s, int value);

void print_set(set *s);

#endif
