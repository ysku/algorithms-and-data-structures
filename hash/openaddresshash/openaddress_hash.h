#ifndef OPENADDRESS_HASH_H
#define OPENADDRESS_HASH_H
#include <stdint.h>
#include <stddef.h>

#define INIT_HASH_SIZE 10

typedef struct {
    char *key;
    char *value;
} openaddress_hash_item;

openaddress_hash_item *create_openaddress_hash_item(char *key, char *value);

typedef struct {
    size_t count;
    size_t size;
    openaddress_hash_item **items;
} openaddress_hash;

openaddress_hash *create_hash(size_t size);

openaddress_hash_item *hash_search(openaddress_hash *hash, char *key);

int hashing(openaddress_hash *hash, char *key);

void hash_insert(openaddress_hash **hash, char *key, char *value);

void hash_delete(openaddress_hash *hash, char *key);

void delete_hash(openaddress_hash *hash);

void print_hash(openaddress_hash *hash);

#endif
