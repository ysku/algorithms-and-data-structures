#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"

binary_tree_node *create_node(int value) {
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
    s->count = 0;
    s->capacity = STACK_SIZE;
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
        printf("stack overflow\n");
        return;
    }
    s->arr[s->count++] = btree_node;
}

binary_tree_node *pop(stack *s) {
    if (is_empty(s)) {
        printf("stack underflow\n");
        return NULL;
    }
    return s->arr[--s->count];
}

binary_tree_node *top(stack *s) {
    if (is_empty(s)) {
        printf("stack underflow\n");
        return NULL;
    }
    return s->arr[s->count - 1];
}

void print_stack(stack *s) {
    for (int i = 0; i < s->count; i++) {
        printf("%d ", s->arr[i]->value);
    }
    printf("\n");
}

void pre_order(binary_tree_node *root) {
    binary_tree_node *current = root;
    stack *s = create_stack();

    while (1) {
        while (current) {
            printf("%d ", current->value);
            if (current->left != NULL) push(s, current);
            current = current->left;
        }

        if (is_empty(s)) {
            printf("\n");
            return;
        }

        current = pop(s);
        current = current->right;
    }
}

void in_order(binary_tree_node *root) {
    binary_tree_node *current = root;
    stack *s = create_stack();
    while (1) {
        while (current) {
            push(s, current);
            current = current->left;
        }

        if (is_empty(s)) {
            printf("\n");
            return;
        }

        current = pop(s);
        printf("%d ", current->value);

        current = current->right;
    }
}

void post_order(binary_tree_node *root) {
    // FIXME: not work properly
    binary_tree_node *current = root;
    stack *s = create_stack();
    while (1) {
        if (current) {
            push(s, current);
            current = current->left;
        } else {
            if (is_empty(s)) {
                printf("\n");
                return;
            } else if (top(s)->right == NULL) {
                current = pop(s);
                printf("%d ", current->value);
                if (current == top(s)->right) {
                    printf("%d ", top(s)->value);
                    pop(s);
                }
            }
            if (!is_empty(s)) current = top(s)->right;
            else current = NULL;
        }
    }
}
