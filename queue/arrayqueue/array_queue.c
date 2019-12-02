#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"

array_queue *create_queue(int size) {
    array_queue *queue = malloc(sizeof(array_queue));
    if (queue == NULL) {
        goto memory_error;
    }
    queue->capacity = size;
    queue->count = 0;
    queue->arr = malloc(sizeof(int) * size);
    if (queue->arr == NULL) {
        goto memory_error;
    }
    return queue;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

void enqueue(array_queue *queue, int value) {
    queue->arr[queue->count++] = value;
}

int dequeue(array_queue *queue) {
    if (is_empty_queue(queue)) {
        printf("empty queue!!\n");
        return -1;
    }
    int value = queue->arr[0];
    int index = 0;
    for (int i = 1; i < queue->count; i++) {
        queue->arr[i-1] = queue->arr[i];
    }
    queue->count--;
    return value;
}

int front(array_queue *queue) {
    if (is_empty_queue(queue)) {
        printf("empty queue!!\n");
        return -1;
    }
    return queue->arr[0];
}

int queue_size(array_queue *queue) {
    return queue->count;
}

int is_empty_queue(array_queue *queue) {
    return queue->count == 0;
}

void delete_queue(array_queue *queue) {
    if (queue) {
        if (queue->arr) {
            free(queue->arr);
        }
        free(queue);
    }
}
