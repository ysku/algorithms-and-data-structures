#ifndef CHAINING_HASH_H
#define CHAINING_HASH_H
#include <stdint.h>
#include <stddef.h>

// TODO: need to resize hash
#define HASH_SIZE 10

typedef struct chaining_hash_item_tag chaining_hash_item;

struct chaining_hash_item_tag {
    char *key;
    char *value;
    chaining_hash_item *next;
};

chaining_hash_item *create_chaining_hash_item(char *key, char *value);

typedef struct {
    size_t count;
    chaining_hash_item *items[HASH_SIZE];
} chaining_hash;

chaining_hash *create_hash();

chaining_hash_item *hash_search(chaining_hash *hash, char *key);

int hashing(char *key);

void hash_insert(chaining_hash *hash, char *key, char *value);

void hash_delete(chaining_hash *hash, char *key);

void delete_hash(chaining_hash *hash);

void print_hash(chaining_hash *hash);

#endif
