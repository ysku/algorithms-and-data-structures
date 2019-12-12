#include <stdio.h>
#include <stdlib.h>
#include "weighted_quick_union.h"

weighted_quick_union *create_weighted_quick_union(int size) {
    weighted_quick_union *u = malloc(sizeof(weighted_quick_union));
    if (!u) goto memory_error;
    u->size = size;
    u->arr = malloc(sizeof(int) * size);
    if (!u->arr) goto memory_error;
    for (int i = 0; i < size; i++) u->arr[i] = i;
    return u;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

int root(weighted_quick_union *u, int v) {
//    for (int i = v; i = u->arr[i]; i = u->arr[i]);
    int i = v;
    while (i != u->arr[i]) i = u->arr[i];
    return i;
}

int find(weighted_quick_union *u, int v1, int v2) {
    return root(u, v1) == root(u, v2);
}

int weight(weighted_quick_union *u, int v) {
    int count = 0;
    for (int i = 0; i < u->size; i++) {
        if (u->arr[i] == v) count++;
    }
    return count;
}

void unite(weighted_quick_union *u, int v1, int v2) {
    int p1 = root(u, v1);
    int p2 = root(u, v2);
    int r1, r2;
    if (weight(u, p1) >= weight(u, p2)) {
        r1 = p1;
        r2 = p2;
    } else {
        r1 = p2;
        r2 = p1;
    }
    u->arr[r2] = u->arr[r1];
}

void print_weighted_quick_union(weighted_quick_union *u) {
    for (int i = 0; i < u->size; i++) printf("%d ", u->arr[i]);
    printf("\n");
}
