#ifndef QUICK_UNION_H
#define QUICK_UNION_H

typedef struct {
    int size;
    int *arr;
} quick_union;

quick_union *create_quick_union(int size);

int find(quick_union *qu, int v1, int v2);

void unite(quick_union *qu, int v1, int v2);

void print_quick_union(quick_union *qu);

#endif
