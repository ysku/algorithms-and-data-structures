#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree_sort.h"

void test_tree_sort() {
    printf("[test] test tree sort started!!\n");

    int numbers[] = {5, 3, 0, 6, 1, 2, 4, 7};
    int n = sizeof(numbers) / sizeof(int);
    int width = 4;

    display(numbers, n);

    int results[n];
    tree_sort(numbers, n, results);

    display(results, n);

    for (int i = 0; i < n; i++) assert( results[i] == i );

    printf("[test] test tree sort finished!!\n");
}

int main() {
    test_tree_sort();
    return 0;
}
