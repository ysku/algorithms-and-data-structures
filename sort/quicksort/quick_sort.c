#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(int *arr, int low, int high) {
    int left = low;
    int right = high;
    int pivot_item = arr[low];
    while (left < right) {
        while (arr[left] <= pivot_item) left++;

        while (arr[right] > pivot_item) right--;

        if (left < right) swap(arr, left, right);
    }

    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}

void quick_sort_recursive(int *arr, int low, int high) {
    int pivot;
    if (high > low) {
        pivot = partition(arr, low, high);
        quick_sort_recursive(arr, low, pivot-1);
        quick_sort_recursive(arr, pivot+1, high);
    }
}

void quick_sort(int *arr, int n) {
    quick_sort_recursive(arr, 0, n);
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
