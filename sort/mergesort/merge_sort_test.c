#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "merge_sort.h"

void test_merge_sort_recursive() {
    printf("[test] test merge sort recursive started!!\n");

    int numbers[] = {5, 3, 0, 6, 1, 2, 4, 7};
    int n = sizeof(numbers) / sizeof(int);

    display(numbers, n);

    int tmp[n];
    for (int i = 0; i < n; i++) tmp[i] = numbers[i];

    merge_sort_recursive(numbers, tmp, n);

    for (int i = 0; i < n; i++) assert( numbers[i] == i );

    printf("[test] test merge sort recursive finished!!\n");
}

int main() {
    test_merge_sort_recursive();
    return 0;
}
