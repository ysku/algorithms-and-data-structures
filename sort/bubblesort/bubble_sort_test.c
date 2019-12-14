#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bubble_sort.h"

void test_bubble_sort() {
    printf("[test] test bubble sort started!!\n");

    int numbers[] = {6, 2, 5, 9, 7, 4, 3, 0, 1, 8};
    int n = sizeof(numbers) / sizeof(int);

    bubble_sort(numbers, n);

    for (int i = 0; i < 10; i++) assert( numbers[i] == i );

    printf("[test] test bubble sort finished!!\n");
}

int main() {
    test_bubble_sort();
    return 0;
}
