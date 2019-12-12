#include <stdio.h>
#include <assert.h>
#include "quick_find.h"

void test_slow_union() {
    printf("[test] test slow union started!!\n");

    quick_find *qf = create_quick_find(10);

    int size = 10;
    int expected1[] = {0, 1, 2, 4, 4, 5, 6, 7, 8, 9};

    unite(qf, 3, 4);
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected1[i] );

    unite(qf, 4, 9);
    int expected2[] = {0, 1, 2, 9, 9, 5, 6, 7, 8, 9};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected2[i] );

    unite(qf, 8, 0);
    int expected3[] = {0, 1, 2, 9, 9, 5, 6, 7, 0, 9};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected3[i] );

    unite(qf, 2, 3);
    int expected4[] = {0, 1, 9, 9, 9, 5, 6, 7, 0, 9};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected4[i] );

    unite(qf, 5, 6);
    int expected5[] = {0, 1, 9, 9, 9, 6, 6, 7, 0, 9};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected5[i] );

    unite(qf, 5, 9);
    int expected6[] = {0, 1, 9, 9, 9, 9, 9, 7, 0, 9};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected6[i] );

    unite(qf, 7, 3);
    int expected7[] = {0, 1, 9, 9, 9, 9, 9, 9, 0, 9};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected7[i] );

    unite(qf, 4, 8);
    int expected8[] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected8[i] );

    unite(qf, 6, 1);
    int expected9[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < size; i++) assert( qf->arr[i] == expected9[i] );

    printf("[test] test slow union finished!!\n");
}

int main() {
    test_slow_union();
    return 0;
}
