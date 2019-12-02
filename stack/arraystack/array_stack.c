#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

array_stack *create_stack(int size) {
    array_stack *stack = malloc(sizeof(array_stack));
    if (stack == NULL) {
        goto memory_error;
    }
    stack->top = -1;
    stack->capacity = size;
    stack->arr = malloc(sizeof(int) * size);
    if (stack->arr == NULL) {
        goto memory_error;
    }
    return stack;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

int is_empty_stack(array_stack *stack) {
    if (stack == NULL) return 1;
    return stack->top == -1;
}

int is_full_stack(array_stack *stack) {
    if (stack == NULL) return 0;
    return stack->top == stack->capacity - 1;
}

void push(array_stack *stack, int value) {
    if (is_full_stack(stack)) {
        printf("stack overflow!!\n");
        return;
    }
    stack->arr[++stack->top] = value;
    return;
}

int pop(array_stack *stack) {
    if (is_empty_stack(stack)) {
        printf("stack underflow!!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int length(array_stack *stack) {
    return stack->top + 1;
}

void delete_stack(array_stack *stack) {
    if (stack) {
        if (stack->arr) {
            free(stack->arr);
        }
        free(stack);
    }
}
