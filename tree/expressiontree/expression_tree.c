#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "expression_tree.h"

binary_tree_node *create_node(char value) {
    binary_tree_node *node = malloc(sizeof(binary_tree_node));
    if (!node) {
        printf("memory error!!\n");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

const int STACK_SIZE = 100;

typedef struct stack {
    int capacity;
    int count;
    binary_tree_node *arr[STACK_SIZE];
} stack;

stack *create_stack() {
    stack *s = malloc(sizeof(stack));
    if (!s) {
        goto memory_error;
    }
    s->capacity = STACK_SIZE;
    s->count = 0;
    return s;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

int is_empty(stack *s) {
    return s->count == 0;
}

int is_full(stack *s) {
    return s->count == s->capacity;
}

void push(stack *s, binary_tree_node *btree_node) {
    if (is_full(s)) {
        printf("stack overflow!!\n");
        return;
    }
    s->arr[s->count++] = btree_node;
}

binary_tree_node *pop(stack *s) {
    if (is_empty(s)) {
        printf("stack underflow!!\n");
        return NULL;
    }
    return s->arr[--s->count];
}

int is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int is_operand(char c) {
    return !is_operator(c);
}

binary_tree_node *build_expr_tree(char postfix_expr[], int size) {
    stack *s = create_stack();
    for (int i = 0; i < size; i++) {
        if (postfix_expr[i] == ' ' || postfix_expr[i] == '\0') {
            continue;
        } else if (is_operand(postfix_expr[i])) {
            binary_tree_node *new_node = create_node(postfix_expr[i]);
            push(s, new_node);
        } else {
            binary_tree_node *t1 = pop(s);
            binary_tree_node *t2 = pop(s);
            binary_tree_node *new_node = create_node(postfix_expr[i]);
            new_node->left = t2;
            new_node->right = t1;
            push(s, new_node);
        }
    }
    return pop(s);
}
