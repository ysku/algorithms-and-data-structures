#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bloom_filter.h"

bloom_filter *create_bloom_filter() {
    bloom_filter *bf = malloc(sizeof(bloom_filter));
    if (bf == NULL) {
        fprintf(stderr, "memory error!!\n");
        return NULL;
    }
    bf->bits = 0;
    return bf;
}

int hash_code(char s[]) {
    int n = strlen(s);
    int h = 0;
    for (int i = 0; i < n; i++) {
        h = 31 * h + s[i];
    }
    return h;
}

void add(bloom_filter *bf, int (*func)(char *), char s[]) {
    int h = hash_code(s);
    bf->bits |= 1 << h;
}

bool contains(bloom_filter *bf, char s[]) {
    int h = hash_code(s);
    if ((bf->bits & 1 << h) == 0) {
        return false;
    }
    return true;
}
