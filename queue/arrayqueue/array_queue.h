#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct array_queue {
    int capacity;
    int count;
    int *arr;
} array_queue;

array_queue *create_queue(int size);

void enqueue(array_queue *queue, int value);

int dequeue(array_queue *queue);

int front(array_queue *queue);

int queue_size(array_queue *queue);

int is_empty_queue(array_queue *queue);

void delete_queue(array_queue *queue);

#endif
