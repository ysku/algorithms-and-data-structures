#include <stdio.h>
#include <assert.h>
#include "quick_union.h"

void test_quick_union() {
    printf("[test] test quick union started!!\n");

    quick_union *qu = create_quick_union(10);

    int size = 10;

    unite(qu, 3, 4);
    int expected1[] = {0, 1, 2, 4, 4, 5, 6, 7, 8, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected1[i] );

    unite(qu, 4, 9);
    int expected2[] = {0, 1, 2, 4, 9, 5, 6, 7, 8, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected2[i] );

    unite(qu, 8, 0);
    int expected3[] = {0, 1, 2, 4, 9, 5, 6, 7, 0, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected3[i] );

    unite(qu, 2, 3);
    int expected4[] = {0, 1, 9, 4, 9, 5, 6, 7, 0, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected4[i] );

    unite(qu, 5, 6);
    int expected5[] = {0, 1, 9, 4, 9, 6, 6, 7, 0, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected5[i] );

    unite(qu, 5, 9);
    int expected6[] = {0, 1, 9, 4, 9, 6, 9, 7, 0, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected6[i] );

    unite(qu, 7, 3);
    int expected7[] = {0, 1, 9, 4, 9, 6, 9, 9, 0, 9};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected7[i] );

    unite(qu, 4, 8);
    int expected8[] = {0, 1, 9, 4, 9, 6, 9, 9, 0, 0};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected8[i] );

    unite(qu, 6, 1);
    int expected9[] = {1, 1, 9, 4, 9, 6, 9, 9, 0, 0};
    print_quick_union(qu);
    for (int i = 0; i < size; i++) assert( qu->arr[i] == expected9[i] );

    printf("[test] test quick union finished!!\n");
}

int main() {
    test_quick_union();

    return 0;
}