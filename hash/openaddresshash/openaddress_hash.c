#include <stdio.h>
#include <stdlib.h>
#include "openaddress_hash.h"

openaddress_hash_item *create_openaddress_hash_item(char *key, char *value) {
    openaddress_hash_item *item = malloc(sizeof(openaddress_hash_item));
    if (item == NULL) {
        printf("memory error!!\n");
        return NULL;
    }
    item->key = key;
    item->value = value;
    return item;
}

openaddress_hash *create_hash(size_t size) {
    openaddress_hash *hash = malloc(sizeof(openaddress_hash));
    if (!hash) {
        printf("memory error!!\n");
        return NULL;
    }
    hash->count = 0;
    hash->size = size;
    hash->items = malloc(sizeof(openaddress_hash_item*) * size);
    for (size_t i = 0; i < hash->size; i++) hash->items[i] = NULL;
    return hash;
}

int hashing(openaddress_hash *hash, char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]) {
        sum += key[i];
        i++;
    }
    return sum % hash->size;
}

int rehashing(openaddress_hash *hash, size_t value) {
    return (value + 1) % hash->size;
}

openaddress_hash *resize(openaddress_hash *hash) {
    size_t size = hash->size * 2;
    openaddress_hash *resized = create_hash(size);
    resized->count = hash->count;
    for (size_t i = 0; i < hash->size; i++) {
        openaddress_hash_item *item = hash->items[i];
        size_t h = hashing(resized, item->key);
        while (resized->items[h] != NULL) {
            h = rehashing(resized, h);
        }
        resized->items[h] = item;
    }
    return resized;
}

openaddress_hash_item *hash_search(openaddress_hash *hash, char *key) {
    size_t h = hashing(hash, key);
    while (hash->items[h] != NULL && hash->items[h]->key != key) {
        h = rehashing(hash, h);
    }
    if (hash->items[h] == NULL) {
        printf("not found!!\n");
        return NULL;
    }
    return hash->items[h];
}

void hash_insert(openaddress_hash **hash, char *key, char *value) {
    printf("hash->count : %zu, hash->size : %zu\n", (*hash)->count, (*hash)->size);
    if ((*hash)->count >= (*hash)->size) {
        *hash = resize(*hash);
    }
    size_t h = hashing(*hash, key);
    while ((*hash)->items[h] != NULL) {
        h = rehashing((*hash), h);
    }
    printf("inserting : %zu\n", h);
    openaddress_hash_item *new_item = create_openaddress_hash_item(key, value);
    (*hash)->items[h] = new_item;
    (*hash)->count++;
    printf("inserted : %zu\n", h);
}

void hash_delete(openaddress_hash *hash, char *key) {
    size_t h = hashing(hash, key);
    while (hash->items[h] != NULL && hash->items[h]->key != key) {
        h = rehashing(hash, h);
    }
    if (hash->items[h] == NULL) {
        printf("not found!!\n");
        return;
    }
    hash->items[h] = NULL;
    hash->count--;
}

void delete_hash(openaddress_hash *hash) {
    if (hash) {
        if (hash->items) {
            free(hash->items);
        }
        free(hash);
    }
}

void print_hash(openaddress_hash *hash) {
    printf(" ***** hash ***** \n");
    printf("size : %zu\n", hash->size);
    for (size_t i = 0; i < hash->size; i++) {
        if (hash->items[i] == NULL) {
            printf("[%zu] Empty... \n", i);
        } else {
            printf("[%zu] key : %s, value : %s\n", i, hash->items[i]->key, hash->items[i]->value);
        }
    }
    printf(" *************** \n");
}
