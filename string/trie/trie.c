#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "trie.h"

trie_node *create_trie_node() {
    trie_node *node = malloc(sizeof(trie_node));
    if (!node) {
        fprintf(stderr, "memory error!!\n");
        return NULL;
    }
    node->is_end_of_word = false;
    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(trie_node *root, char *word) {
    for (size_t i = 0; i < strlen(word); i++) {
        char character = word[i];
        if (root->children[character-97] == NULL) {
            trie_node *node = create_trie_node();
            node->character = character;
            root->children[character-97] = node;
        }
        root = root->children[character-97];
    }
    root->is_end_of_word = true;
}

bool search(trie_node *root, char *word) {
    printf("searching word : %s\n", word);

    size_t idx = 0;
    while (word[idx] != '\0') {
        char character = word[idx];
        if (root->children[character-97] != NULL) {
            root = root->children[character-97];
            idx++;
        } else {
            return false;
        }
    }
    return true;
}

const size_t STACK_SIZE = 100;

typedef struct {
    size_t count;
    size_t capacity;
    trie_node *arr[STACK_SIZE];
} stack;

stack *create_stack() {
    stack *s = malloc(sizeof(stack));
    if (!s) {
        fprintf(stderr, "memory error!!\n");
        return NULL;
    }
    s->capacity = STACK_SIZE;
    s->count = 0;
    for (size_t i = 0; i < STACK_SIZE; i++) {
        s->arr[i] = NULL;
    }
    return s;
}

bool is_empty_stack(stack *s) {
    return s->count == 0;
}

bool is_full_stack(stack *s) {
    return s->count == s->capacity;
}

void push(stack *s, trie_node *node) {
    if (is_full_stack(s)) {
        printf("stack overflow!!\n");
        return;
    }
    s->arr[s->count++] = node;
}

trie_node *pop(stack *s) {
    if (is_empty_stack(s)) {
        printf("stack underflow!!\n");
        return NULL;
    }
    trie_node *node = s->arr[--s->count];
    s->arr[s->count+1] = NULL;
    return node;
}

void traverse(trie_node *root) {
    stack *s = create_stack();
    while (1) {
        for (size_t i = 0; i < ALPHABET_SIZE; i++) {
            if (root->children[i] != NULL) {
                printf("%c", root->children[i]->character);
                push(s, root->children[i]);
            }
        }
        if (is_empty_stack(s)) {
            return;
        }
        root = pop(s);
    }
}
