#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "two_three_four_tree.h"

node *create_node() {
    node *n = malloc(sizeof(node));
    if (!n) {
        goto memory_error;
    }
    n->word = malloc(sizeof(char) * 4);
    if (!n->word) {
        goto memory_error;
    }
    n->count = 0;
    n->parent = NULL;
    n->first = NULL;
    n->second = NULL;
    n->third = NULL;
    n->fourth = NULL;
    return n;
memory_error:
    fprintf(stderr, "memory error!!\n");
    return NULL;
}

void insert_a_character(node *root, char character) {
    printf("[insert_a_character] insert %c to root[%s]\n", character, root->word);
    if (root->count == 0) {
        root->word[root->count++] = character;
        return;
    }

    char prev = character;
    for (size_t i = 0; i < root->count; i++) {
        if (root->word[i] > prev) {
            char tmp = root->word[i];
            root->word[i] = prev;
            prev = tmp;
        }
    }
    root->word[root->count++] = prev;
    printf("inserted, node : %s\n", root->word);
}

void split_node_no_parent(node *root) {

}

void split(node **root) {
    assert( (*root)->count == 4 );

    if (!(*root)->parent) {
        printf("node that does not have parent\n");
        node *new_node = create_node();
        new_node->word[0] = (*root)->word[2];

        node *first = create_node();
        first->word[0] = (*root)->word[0];
        first->word[1] = (*root)->word[1];
        first->count = 2;
        first->parent = new_node;

        node *second = create_node();
        second->word[0] = (*root)->word[3];
        second->count = 1;
        second->parent = new_node;

        new_node->first = first;
        new_node->second = second;

        delete_node(*root);

        *root = new_node;
    } else if ((*root)->parent->second == *root) {
        printf("node that has parent, and is its second child\n");
        (*root)->parent->word[1] = (*root)->word[2];
        (*root)->parent->count++;

        node *second = create_node();
        second->word[0] = (*root)->word[0];
        second->word[1] = (*root)->word[1];
        second->count += 2;
        second->parent = (*root)->parent;

        node *third = create_node();
        third->word[0] = (*root)->word[3];
        third->count++;
        third->parent = (*root)->parent;

        (*root)->parent->second = second;
        (*root)->parent->third = third;
    } else {
        printf("node that has parent that has three children, and is its first child\n");
        node *new_node = create_node();
        new_node->word[0] = (*root)->parent->word[1];
        new_node->count++;
        new_node->parent = *root;

        node *new_first = (*root)->parent->second;
        node *new_second = (*root)->parent->third;
        new_node->first = new_first;
        new_node->second = new_second;
        new_first->parent = new_node;
        new_second->parent = new_node;

        (*root)->parent->word[1] = '\0';
        (*root)->parent->second = new_node;
        (*root)->parent->third = NULL;

        node *first = create_node();
        first->word[0] = (*root)->word[0];
        first->count = 1;
        first->parent = (*root);

        node *second = create_node();
        second->word[0] = (*root)->word[2];
        second->word[1] = (*root)->word[3];
        second->count = 2;
        second->parent = (*root);

        (*root)->first = first;
        (*root)->second = second;
        (*root)->word = "A";
        (*root)->count = 1;
    }
}

int num_of_children(node *root) {
    if (!root->first) {
        return 0;
    } else if (root->first && root->second && !root->third && !root->fourth) {
        return 2;
    } else if (root->first && root->second && root->third && !root->fourth) {
        return 3;
    } else {
        printf("something wrong!!\n");
        return -1;
    }
}

void insert(node **root, char character) {
    printf("inserting %c\n", character);

    if (num_of_children(*root) == 0) {
        insert_a_character(*root, character);
        if ((*root)->count == 4) {
            split(root);
        }
        return;
    }

    node *child = *root;
    while (num_of_children(child) != 0) {
        if (num_of_children(child) == 2) {
            if (child->word[0] >= character) {
                child = child->first;
            } else {
                child = child->second;
            }
        } else {
            // when num of children is 3
            if (child->word[0] >= character) {
                child = child->first;
            } else if (child->word[0] < character && child->word[1] >= character) {
                child = child->second;
            } else {
                child = child->third;
            }
        }
    }

    printf("child : %s\n", child->word);
    insert_a_character(child, character);
    if (child->count == 4) {
        split(&child);
    }
    return;
}

void delete_node(node *root) {
    if (root) {
        if (root->parent) {
            free(root->parent);
            root->parent = NULL;
        }
        if (root->first) {
            free(root->first);
            root->first = NULL;
        }
        if (root->second) {
            free(root->second);
            root->second = NULL;
        }
        if (root->third) {
            free(root->third);
            root->third = NULL;
        }
        if (root->fourth) {
            free(root->fourth);
            root->fourth = NULL;
        }
        free(root);
        root = NULL;
    }
}
