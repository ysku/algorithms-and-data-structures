#include <stdio.h>
#include <math.h>
#include "merge_sort.h"

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void merge(int *arr, int *tmp, int left, int mid, int right) {
    int left_end = mid - 1;
    int tmp_pos = left;
    int size = right - left + 1;

    while ((left <= left_end) && (mid <= right)) {
        if (arr[left] <= arr[mid]) {
            tmp[tmp_pos] = arr[left];
            tmp_pos++;
            left++;
        } else {
            tmp[tmp_pos] = arr[mid];
            tmp_pos++;
            mid++;
        }
    }

    /* left list */
    while (left <= left_end) {
        tmp[tmp_pos] = arr[left];
        left++;
        tmp_pos++;
    }

    /* right list */
    while (mid <= right) {
        tmp[tmp_pos] = arr[mid];
        mid++;
        tmp_pos++;
    }

    for (int i = 0; i <= size; i++) {
        arr[right] = tmp[right];
        right--;
    }
}

void m_sort(int *arr, int *tmp, int left, int right) {
    if (right > left) {
        int mid = (right + left) / 2;
        m_sort(arr, tmp, left, mid);
        m_sort(arr, tmp, mid+1, right);
        merge(arr, tmp, left, mid+1, right);
    }
}

void merge_sort_recursive(int *arr, int *tmp, int n) {
    m_sort(arr, tmp, 0, n - 1);
}
