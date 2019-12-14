#include <stdio.h>
#include "shell_sort.h"

void swap(int *arr, int i, int j) {
    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void shell_sort(int *arr, int n, int width) {
    while (width > 0) {
        for (int i = 0; i < n - width; i++) {
            if (arr[i] > arr[i + width]) {
                swap(arr, i, i + width);
            }
        }
        display(arr, n);
        width = (int)(width / 2);
    }
}
