#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

typedef struct {
    int count;
    int capacity;
    int *arr;
} heap;

heap *create_heap(int size) {
    heap *h = malloc(sizeof(heap));
    if (!h) {
        printf("memory error!!\n");
        return NULL;
    }
    h->count = 0;
    h->capacity = size;
    h->arr = malloc(sizeof(int) * size);
    if (!h->arr) {
        printf("memory error!!\n");
        return NULL;
    }
    return h;
}

void print_heap(heap *h) {
    for (int i = 0; i < h->count; i++) printf("%d ", h->arr[i]);
    printf("\n");
}

int is_empty_heap(heap *h) {
    if (!h) return 1;
    return h->count == 0;
}

int get_parent_idx(int child_idx) {
    // 3, 4 -> 1
    // 5, 6 -> 2
    // 7, 8 -> 3
    // 1, 2 -> 0
    return (child_idx - 1) / 2;
}

void heapify(heap *h) {
    for (int i = h->count - 1; i >= 0; i--) {
        int child_idx = i;
        int parent_idx = get_parent_idx(child_idx);
        if (h->arr[child_idx] < h->arr[parent_idx]) {
            int tmp = h->arr[child_idx];
            h->arr[child_idx] = h->arr[parent_idx];
            h->arr[parent_idx] = tmp;
        }
    }
}

void add_value(heap *h, int value) {
    h->arr[h->count++] = value;
    heapify(h);
    print_heap(h);
}

int get_value(heap *h) {
    if (is_empty_heap(h)) {
        printf("heap is empty!!\n");
        return -1;
    }
    int ret = h->arr[0];
    h->count--;
    for (int i = 0; i < h->count; i++) {
        h->arr[i] = h->arr[i+1];
    }
    heapify(h);
    print_heap(h);
    return ret;
}

void heap_sort(int *arr, int n, int *results) {
    heap *h = create_heap(n);
    for (int i = 0; i < n; i++) {
        add_value(h, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        results[i] = get_value(h);
    }
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
