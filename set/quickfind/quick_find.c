#include <stdio.h>
#include <stdlib.h>
#include "quick_find.h"

quick_find *create_quick_find(int size) {
    quick_find *qf = malloc(sizeof(quick_find));
    if (!qf) goto memory_error;
    qf->size = size;
    qf->arr = malloc(sizeof(int) * size);
    if (!qf->arr) goto memory_error;
    for (int i = 0; i < size; i++) qf->arr[i] = i;
    return qf;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

int find(quick_find *qf, int v1, int v2) {
    if (!(0 <= v1 && v1 < qf->size)) goto not_connected;
    if (!(0 <= v2 && v2 < qf->size)) goto not_connected;

    return qf->arr[v1] == qf->arr[v2];
not_connected:
    printf("not connected!!\n");
    return -1;
}

void unite(quick_find *qf, int v1, int v2) {
    if (!(0 <= v1 && v1 < qf->size)) goto invalid_value;
    if (!(0 <= v2 && v2 < qf->size)) goto invalid_value;
    int value = qf->arr[v1];
    for (int i = 0; i < qf->size; i++) {
        if (qf->arr[i] == value) qf->arr[i] = qf->arr[v2];
    }
    return;
invalid_value:
    printf("invalid value is set!!\n");
    return;
}

void print_quick_find(quick_find *qf) {
    for (int i = 0; i < qf->size; i++) {
        printf("%d ", qf->arr[i]);
    }
    printf("\n");
}
