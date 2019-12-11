#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <stdio.h>

typedef struct {
    int count;
    int capacity;
    int *arr;
} heap;

heap *create_heap(int capacity);

int dequeue(heap *h);

void enqueue(heap *h, int value);

void display(heap *h);

#endif
