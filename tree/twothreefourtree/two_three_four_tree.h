#ifndef TWO_THREE_FOUR_TREE_H
#define TWO_THREE_FOUR_TREE_H

typedef struct node_tag node;

struct node_tag {
    char *word;
    size_t count;
    node *parent;
    node *first;
    node *second;
    node *third;
    node *fourth;
};

node *create_node();

void insert_a_character(node *root, char character);

void split(node **root);

void insert(node **root, char character);

void delete_node(node *root);

#endif
