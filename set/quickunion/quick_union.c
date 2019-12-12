#include <stdio.h>
#include <stdlib.h>
#include "quick_union.h"

quick_union *create_quick_union(int size) {
    quick_union *qu = malloc(sizeof(quick_union));
    if (!qu) goto memory_error;
    qu->size = size;
    qu->arr = malloc(sizeof(int) * size);
    if (!qu->arr) goto memory_error;
    for (int i = 0; i < size; i++) qu->arr[i] = i;
    return qu;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

int root(quick_union *qu, int i) {
    while (i != qu->arr[i]) i = qu->arr[i];
    return i;
}

int find(quick_union *qu, int v1, int v2) {
    // check if v1 and v2 have the same root.
    return root(qu, v1) == root(qu, v2);
}

void invalid_value(int value) {
    printf("invalid value : %d\n", value);
}

void unite(quick_union *qu, int v1, int v2) {
    if (!(0 <= v1 && v1 < qu->size)) return invalid_value(v1);
    if (!(0 <= v2 && v2 < qu->size)) return invalid_value(v2);

    int p1 = root(qu, v1);
    int p2 = root(qu, v2);
    qu->arr[p1] = p2;
    return;
}

void print_quick_union(quick_union *qu) {
    for (int i = 0; i < qu->size; i++) {
        printf("%d ", qu->arr[i]);
    }
    printf("\n");
}
