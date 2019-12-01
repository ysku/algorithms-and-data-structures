#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circular_list.h"

circular_list_node *new_circular_list_node(int value) {
    circular_list_node *new_node = malloc(sizeof(circular_list_node));
    if (!new_node) {
        printf("memory error!!");
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert(circular_list_node *root, int value) {
    circular_list_node *new_node = new_circular_list_node(value);
    if (!root) {
        root = new_node;
        root->next = root;
        return;
    }
    circular_list_node *current = root;
    while (current->next != root) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = root;
    return;
}

int length(circular_list_node *root) {
    int count = 0;
    if (!root) {
        return count;
    }
    circular_list_node *current = root;
    count++;
    while (current->next != root) {
        count++;
        current = current->next;
    }
    return count;
}

circular_list_node *get(circular_list_node *root, int i) {
    assert( i >= 0 );
    if (!root) {
        printf("empty list!\n");
        return NULL;
    }

    int index = 0;
    circular_list_node *current = root;

    while (index < i && current->next != root) {
        index++;
        current = current->next;
    }
    if (index == i) {
        return current;
    } else {
        return NULL;
    }
}

circular_list_node *delete(circular_list_node *root, int i) {
    assert( i >= 0 );
    if (!root) {
        printf("empty list!\n");
        return NULL;
    }
    if (i == 0) {
        circular_list_node *node = root;
        free(root);
        return node;
    }

    int index = 1;
    circular_list_node *current = root->next;
    while (index < i - 1 && current->next != root) {
        index++;
        current = current->next;
    }
    if (index == i - 1) {
        circular_list_node *node = current->next;
        free(current->next);
        current->next = current->next->next;
        return node;
    } else {
        printf("not found\n");
        return NULL;
    }
}

circular_list_node *pop(circular_list_node **root) {
    if (!root) {
        printf("empty list!\n");
        return NULL;
    }
    if ((*root)->next == *root) {
        circular_list_node *node = *root;
        free(*root);
        return node;
    }
    circular_list_node *head = *root;
    circular_list_node *node = *root;
    circular_list_node *current = *root;
    while (current->next != head) {
        current = current->next;
    }
    current->next = head->next;
    *root = head->next;
    free(head);
    return node;
}
