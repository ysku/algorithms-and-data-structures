#ifndef WEIGHTED_QUICK_UNION_H
#define WEIGHTED_QUICK_UNION_H

typedef struct {
    int size;
    int *arr;
} weighted_quick_union;

weighted_quick_union *create_weighted_quick_union(int size);

int find(weighted_quick_union *u, int v1, int v2);

void unite(weighted_quick_union *u, int v1, int v2);

void print_weighted_quick_union(weighted_quick_union *u);

#endif
