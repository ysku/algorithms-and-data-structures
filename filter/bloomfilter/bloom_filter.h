#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdbool.h>

typedef struct bloom_filter_tag {
    int bits;
} bloom_filter;

bloom_filter *create_bloom_filter();

int hash_code(char s[]);

void add(bloom_filter *bf, int (*func)(char *), char s[]);

bool contains(bloom_filter *bf, char s[]);

#endif
