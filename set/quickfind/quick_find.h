#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct {
    int size;
    int *arr;
} quick_find;

quick_find *create_quick_find(int size);

int find(quick_find *qf, int v1, int v2);

void unite(quick_find *qf, int v1, int v2);

void print_quick_find(quick_find *qf);

#endif
