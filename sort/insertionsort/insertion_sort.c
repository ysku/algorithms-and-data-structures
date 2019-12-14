#include <stdio.h>
#include "insertion_sort.h"

void swap(int *arr, int i, int j) {
    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int v = arr[i];
        int j = i;
        while (arr[j - 1] > v && j >= 1) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = v;
        display(arr, n);
    }
}
