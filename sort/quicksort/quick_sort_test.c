#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quick_sort.h"

void test_quick_sort() {
    printf("[test] test quick sort started!!\n");

    int numbers[] = {6, 2, 5, 9, 7, 4, 3, 0, 1, 8};
    int n = sizeof(numbers) / sizeof(int);

    int results[n];
    quick_sort(numbers, n);

    display(numbers, n);

    for (int i = 0; i < 10; i++) assert( numbers[i] == i );

    printf("[test] test quick sort finished!!\n");
}

int main() {
    test_quick_sort();
    return 0;
}
