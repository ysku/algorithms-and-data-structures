#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap_sort.h"

void test_heap_sort() {
    printf("[test] test heap sort started!!\n");

    int numbers[] = {6, 2, 5, 9, 7, 4, 3, 0, 1, 8};
    int n = sizeof(numbers) / sizeof(int);

    int results[n];
    heap_sort(numbers, n, results);

    display(results, n);

    for (int i = 0; i < 10; i++) assert( results[i] == i );

    printf("[test] test heap sort finished!!\n");
}

int main() {
    test_heap_sort();
    return 0;
}
