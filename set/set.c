#include <stdio.h>
#include <stdlib.h>
#include "set.h"

node *create_node(int value) {
    node *n = malloc(sizeof(node));
    if (!n) {
        printf("memory error!!\n");
        return NULL;
    }
    n->value = value;
    n->next = NULL;
    return n;
}

set *create_set() {
    set *s = malloc(sizeof(set));
    if (!s) {
        printf("memory error!!\n");
        return NULL;
    }
    s->count = 0;
    s->next = NULL;
    return s;
}

int length(set *s) {
    return s->count;
}

void add_value(set *s, int value) {
    node *new_node = create_node(value);
    if (s->next == NULL) {
        s->next = new_node;
        s->count++;
        return;
    }
    node *current = s->next;
    while (current->next != NULL) {
        if (current->value == value) return;
        current = current->next;
    }
    current->next = new_node;
    s->count++;
    return;
}

int remove_value(set *s, int value) {
    node *prev = NULL;
    node *current = s->next;
    while (current->next != NULL) {
        if (current->value == value) {
            if (prev == NULL) {
                s->next = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            s->count--;
            return value;
        }
        prev = current;
        current = current->next;
    }
    if (current->value == value) {
        prev = NULL;
        s->count--;
        return value;
    }
    printf("%d not found\n", value);
    return -1;
}

void print_set(set *s) {
    node *current = s->next;
    printf("%d", current->value);
    while (current->next != NULL) {
        current = current->next;
        printf(",%d", current->value);
    }
    printf("\n");
}
