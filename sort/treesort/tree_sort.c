#include <stdio.h>
#include <stdlib.h>
#include "tree_sort.h"

#define MAX_STACK_SIZE 100

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

typedef struct bstree_node_tag bstree_node;

struct bstree_node_tag {
    int value;
    bstree_node *left;
    bstree_node *right;
};

bstree_node *create_bstree_node(int value) {
    bstree_node *node = malloc(sizeof(bstree_node));
    if (!node) {
        printf("memory error!!\n");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct {
    int num_of_nodes;
    bstree_node *root;
} bstree;

bstree *create_bstree() {
    bstree *tree = malloc(sizeof(bstree));
    if (!tree) {
        printf("memory error!!\n");
        return NULL;
    }
    tree->num_of_nodes = 0;
    tree->root = NULL;
    return tree;
}

void insert(bstree *tree, int value) {
    if (!tree->root) {
        tree->root = create_bstree_node(value);
        tree->num_of_nodes++;
        return;
    }
    bstree_node *current = tree->root;
    while (current) {
        if (current->value > value) {
            if (!current->left) {
                current->left = create_bstree_node(value);
                tree->num_of_nodes++;
                return;
            } else {
                current = current->left;
            }
        } else {
            if (!current->right) {
                current->right = create_bstree_node(value);
                tree->num_of_nodes++;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

typedef struct stack_tag {
    int size;
    int count;
    bstree_node *arr[MAX_STACK_SIZE];
} stack;

stack *create_stack(int size) {
    stack *s = malloc(sizeof(stack));
    if (!s) {
        printf("memory error!!\n");
        return NULL;
    }
    s->size = size;
    s->count = 0;
    return s;
}

int is_empty_stack(stack *s) {
    if (!s) return 1;
    return s->count == 0;
}

int is_full_stack(stack *s) {
    return s->count == s->size;
}

void push(stack *s, bstree_node *node) {
    if (is_full_stack(s)) {
        printf("stack overflow!!\n");
        return;
    }
    s->arr[s->count++] = node;
}

bstree_node *pop(stack *s) {
    if (is_empty_stack(s)) {
        printf("stack underflow\n");
        return NULL;
    }
    bstree_node *node = s->arr[s->count - 1];
    s->count--;
    return node;
}

void traverse(bstree *tree, int *results) {
    int idx = 0;
    bstree_node *current = tree->root;
    stack *s = create_stack(tree->num_of_nodes);

    while (1) {
        while (current) {
            push(s, current);
            current = current->left;
        }

        if (is_empty_stack(s)) break;

        current = pop(s);
        results[idx++] = current->value;

        current = current->right;
    }
}

void tree_sort(int *arr, int n, int *results) {
    bstree *tree = create_bstree();
    for (int i = 0; i < n; i++) {
        insert(tree, arr[i]);
    }
    traverse(tree, results);
}
