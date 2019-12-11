#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

heap *create_heap(int capacity) {
    heap *h = malloc(sizeof(heap));
    if (!h) {
        goto memory_error;
    }
    h->capacity = capacity;
    h->count = 0;
    h->arr = malloc(sizeof(int) * capacity);
    if (!h->arr) {
        goto memory_error;
    }
    return h;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

int is_empty(heap *h) {
    if (!h) return 1;
    return h->count == 0;
}

int is_full(heap *h) {
    return h->count == h->capacity;
}

int get_left_child_idx(int parent_idx) {
    return parent_idx * 2 + 1;
}

int get_right_child_idx(int parent_idx) {
    return parent_idx * 2 + 2;
}

int get_parent_idx(int child_idx) {
    return (int)((child_idx - 1) / 2);
}

void heapify(heap *h) {
    // 0 -> 1, 2
    // 1 -> 3, 4
    // 2 -> 5, 6
    // 3 -> 7, 8
    // parent_idx -> ( parent_idx * 2 + 1, parent_idx * 2 + 2 )
    // parent_idx = ( child_idx - 1 ) / 2
    for (int i = h->count - 1; i >= 0; i--) {
        int child_idx = i;
        int parent_idx = get_parent_idx(child_idx);
        if (h->arr[child_idx] > h->arr[parent_idx]) {
            int tmp = h->arr[child_idx];
            h->arr[child_idx] = h->arr[parent_idx];
            h->arr[parent_idx] = tmp;
        }
    }
}

int dequeue(heap *h) {
    if (is_empty(h)) {
        printf("underflow!!\n");
        return -1;
    }
    int ret = h->arr[0];
    for (int i = 0; i < h->count - 1; i++) {
        h->arr[i] = h->arr[i+1];
    }
    h->count--;
    heapify(h);
    return ret;
}

void enqueue(heap *h, int value) {
    if (is_full(h)) {
        printf("overflow!!\n");
        return;
    }
    h->arr[h->count++] = value;
    heapify(h);
}

void display(heap *h) {
    printf(" === heap === \n");
    for (int i = 0; i < h->count; i++) {
        printf("idx : %d, value : %d\n", i, h->arr[i]);
    }
    printf(" ============ \n");
}
