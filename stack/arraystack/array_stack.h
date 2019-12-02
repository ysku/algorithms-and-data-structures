#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct array_stack {
    int top;
    int capacity;
    int *arr;
} array_stack;

array_stack *create_stack(int size);

int is_empty_stack(array_stack *stack);

int is_full_stack(array_stack *stack);

void push(array_stack *stack, int value);

int pop(array_stack *stack);

int length(array_stack *stack);

void delete_stack(array_stack *stack);

#endifs
