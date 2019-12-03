#include <stdio.h>
#include <stdlib.h>
#include "linked_list_stack.h"

linked_list_node *create_linked_list_node(int value) {
    linked_list_node *node = malloc(sizeof(linked_list_node));
    if (!node) {
        printf("memory error!!\n");
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

linked_list_stack *create_linked_list_stack(int size) {
    linked_list_stack *stack = malloc(sizeof(linked_list_stack));
    if (!stack) {
        printf("memory error!!\n");
        return NULL;
    }
    stack->list = NULL;
    return stack;
}

int is_empty_stack(linked_list_stack *stack) {
    if (!stack) return 1;
    if (!stack->list) return 1;
    return 0;
}

void push(linked_list_stack *stack, int value) {
    linked_list_node *new_node = create_linked_list_node(value);
    if (is_empty_stack(stack)) {
        stack->list = new_node;
        return;
    }
    linked_list_node *current = stack->list;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    return;
}

int pop(linked_list_stack *stack) {
    if (is_empty_stack(stack)) {
        printf("empty stack!!\n");
        return -1;
    }
    int retval;
    linked_list_node *prev = stack->list;
    linked_list_node *current = stack->list->next;
    if (!current) {
        retval = stack->list->value;
        free(stack->list);
        stack->list = NULL;
        return retval;
    }
    while (current->next) {
        prev = current;
        current = current->next;
    }
    retval = current->value;
    free(current);
    prev->next = NULL;
    return retval;
}

int length(linked_list_stack *stack) {
    if (is_empty_stack(stack)) {
        return 0;
    }
    int count = 1;
    linked_list_node *current = stack->list;
    while (current->next) {
        count++;
        current = current->next;
    }
    return count;
}

void delete_stack(linked_list_stack *stack) {
    if (stack) {
        if (stack->list) {
            free(stack->list);
        }
        free(stack);
    }
}
