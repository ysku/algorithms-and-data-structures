#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "shell_sort.h"

void test_shell_sort() {
    printf("[test] test shell sort started!!\n");

    int numbers[] = {5, 3, 0, 6, 1, 2, 4, 7};
    int n = sizeof(numbers) / sizeof(int);
    int width = 4;

    display(numbers, n);

    shell_sort(numbers, n, width);

    for (int i = 0; i < n; i++) assert( numbers[i] == i );

    printf("[test] test shell sort finished!!\n");
}

int main() {
    test_shell_sort();
    return 0;
}
