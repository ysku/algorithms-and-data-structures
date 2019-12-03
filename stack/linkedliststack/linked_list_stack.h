#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

typedef struct linked_list_node_tag linked_list_node;

struct linked_list_node_tag {
    int value;
    linked_list_node *next;
};

linked_list_node *create_linked_list_node(int value);

typedef struct linked_list_stack {
    linked_list_node *list;
} linked_list_stack;

linked_list_stack *create_linked_list_stack(int size);

int is_empty_stack(linked_list_stack *stack);

void push(linked_list_stack *stack, int value);

int pop(linked_list_stack *stack);

int length(linked_list_stack *stack);

void delete_stack(linked_list_stack *stack);

#endif
