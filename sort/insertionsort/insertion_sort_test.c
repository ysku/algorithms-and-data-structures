#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "insertion_sort.h"

void test_insertion_sort() {
    printf("[test] test insertion sort started!!\n");

    int numbers[] = {5, 3, 4, 7, 2, 8, 6, 9, 1};
    int n = sizeof(numbers) / sizeof(int);

    insertion_sort(numbers, n);

    for (int i = 1; i <= n; i++) assert( numbers[i - 1] == i );

    printf("[test] test insertion sort finished!!\n");
}

int main() {
    test_insertion_sort();
    return 0;
}
