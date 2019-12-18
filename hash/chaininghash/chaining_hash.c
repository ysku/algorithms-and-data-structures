#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "chaining_hash.h"

chaining_hash_item *create_chaining_hash_item(char *key, char *value) {
    chaining_hash_item *item = malloc(sizeof(chaining_hash_item));
    if (!item) {
        printf("memory error!!");
        return NULL;
    }
    item->key = key;
    item->value = value;
    item->next = NULL;
    return item;
}

chaining_hash *create_hash() {
    chaining_hash *hash = malloc(sizeof(chaining_hash));
    if (!hash) {
        printf("memory error!!");
        return NULL;
    }
    hash->count = 0;
    for (size_t i = 0; i < HASH_SIZE; i++) {
        hash->items[i] = NULL;
    }
    return hash;
}

int hashing(char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]) {
        sum += key[i];
        i++;
    }
    return sum % HASH_SIZE;
}

chaining_hash_item *hash_search(chaining_hash *hash, char *key) {
    size_t h = hashing(key);

    chaining_hash_item *current = hash->items[h];
    while (current != NULL && current->key != key) {
        current = current->next;
    }
    return current;
}

void hash_insert(chaining_hash *hash, char *key, char *value) {
    size_t h = hashing(key);

    chaining_hash_item *new_item = create_chaining_hash_item(key, value);
    if (new_item == NULL) {
        printf("failed to insert item\n");
        return;
    }
    if (hash->items[h] == NULL) {
        hash->items[h] = new_item;
    } else {
        chaining_hash_item *current = hash->items[h];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_item;
    }
    hash->count++;
    printf("hashed %zu, inserting key : %s, value : %s\n", h, key, value);
}

void hash_delete(chaining_hash *hash, char *key) {
    size_t h = hashing(key);

    chaining_hash_item *current = hash->items[h];
    chaining_hash_item *prev = hash->items[h];
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("not found!!\n");
        return;
    }
    prev->next = current->next;
    hash->count--;
}

void delete_hash(chaining_hash *hash) {
    for (size_t i = 0; i < HASH_SIZE; i++) {
        chaining_hash_item *current = hash->items[i];
        if (!current) {
            continue;
        }
        while (current) {
            chaining_hash_item *tmp = current->next;;
            free(current);
            current = tmp;
        }
        hash->items[i] = NULL;
    }
    free(hash);
}

void print_hash(chaining_hash *hash) {
    printf(" ***** hash ***** \n");
    for (size_t i = 0; i < HASH_SIZE; i++) {
        chaining_hash_item *current = hash->items[i];
        if (!current) {
            continue;
        }
        printf("[%zu] key : %s, values : ", i, current->key);
        while (current) {
            printf("%s ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}
