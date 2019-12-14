#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "selection_sort.h"

void test_selection_sort() {
    printf("[test] test selection sort started!!\n");

    int numbers[] = {6, 2, 5, 9, 7, 4, 3, 0, 1, 8};
    int n = sizeof(numbers) / sizeof(int);

    selection_sort(numbers, n);

    for (int i = 0; i < 10; i++) assert( numbers[i] == i );

    printf("[test] test selection sort finished!!\n");
}

int main() {
    test_selection_sort();
    return 0;
}
