#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

linked_list_node *new_linked_list_node(int value) {
    linked_list_node *l = malloc(sizeof(linked_list_node));
    if (!l) {
        printf("Memory Error!!\n");
        return NULL;
    }
    l->next = NULL;
    l->value = value;
    return l;
};

void insert(linked_list_node *l, int value) {
    if (!l) {
        l = new_linked_list_node(value);
        return;
    }
    linked_list_node *prev = l;
    linked_list_node *current = l->next;
    while (current && current->value < value) {
        prev = current;
        current = current->next;
    }
    linked_list_node *new_node = new_linked_list_node(value);
    prev->next = new_node;
    new_node->next = current;
}

int length(linked_list_node *l) {
    int count = 0;
    if (!l) {
        return count;
    }
    linked_list_node *current = l->next;
    count++;
    while (current) {
        current = current->next;
        count++;
    }
    return count;
}

linked_list_node *get(linked_list_node *l, int i) {
    if (!l) {
        goto NotFound;
    }
    int index = 0;
    if (i == index) {
        return l;
    }
    linked_list_node *current = l->next;
    index++;
    while (current && index < i) {
        current = current->next;
    }
    if (!current) {
        goto NotFound;
    }
    return current;
NotFound:
    printf("empty list!!\n");
    return NULL;
}

linked_list_node *delete_node(linked_list_node *l, int i) {
    if (!l) {
        printf("empty list!!\n");
        return NULL;
    }
    linked_list_node *retval;
    if (i == 0) {
        retval = l;
        l = l->next;
        return retval;
    }
    int index = 1;
    linked_list_node *prev = l;
    linked_list_node *current = l->next;
    while (index < i) {
        prev = current;
        current = current->next;
        index++;
    }
    retval = current;
    prev->next = current->next;
    free(current);
    return retval;
}

linked_list_node *pop(linked_list_node **l) {
    if (!l) {
        printf("empty list!!\n");
        return NULL;
    }
    linked_list_node *retval = *l;
    linked_list_node *p = *l;
    *l = p->next;
    free(p);
    return retval;
}
