#include <stdio.h>
#include "selection_sort.h"

void swap(int *arr, int i, int j) {
    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}

void selection_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr, i, min);
    }
}
