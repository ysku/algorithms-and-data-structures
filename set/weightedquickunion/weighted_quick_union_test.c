#include <stdio.h>
#include <assert.h>
#include "weighted_quick_union.h"

void test_weighted_quick_union() {
    printf("[test] test weighted quick union started!!\n");

    weighted_quick_union *u = create_weighted_quick_union(10);

    int size = 10;
    unite(u, 3, 4);
    int expected1[] = {0, 1, 2, 3, 3, 5, 6, 7, 8, 9};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected1[i] );

    unite(u, 4, 9);
    int expected2[] = {0, 1, 2, 3, 3, 5, 6, 7, 8, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected2[i] );

    unite(u, 8, 0);
    int expected3[] = {8, 1, 2, 3, 3, 5, 6, 7, 8, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected3[i] );

    unite(u, 2, 3);
    int expected4[] = {8, 1, 3, 3, 3, 5, 6, 7, 8, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected4[i] );

    unite(u, 5, 6);
    int expected5[] = {8, 1, 3, 3, 3, 5, 5, 7, 8, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected5[i] );

    unite(u, 5, 9);
    int expected6[] = {8, 1, 3, 3, 3, 3, 5, 7, 8, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected6[i] );

    unite(u, 7, 3);
    int expected7[] = {8, 1, 3, 3, 3, 3, 5, 3, 8, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected7[i] );

    unite(u, 4, 8);
    int expected8[] = {8, 1, 3, 3, 3, 3, 5, 3, 3, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected8[i] );

    unite(u, 6, 1);
    int expected9[] = {8, 3, 3, 3, 3, 3, 5, 3, 3, 3};
    print_weighted_quick_union(u);
    for (int i = 0; i < size; i++) assert( u->arr[i] == expected9[i] );

    printf("[test] test weighted quick union finished!!\n");
}

int main() {
    test_weighted_quick_union();
    return 0;
}
