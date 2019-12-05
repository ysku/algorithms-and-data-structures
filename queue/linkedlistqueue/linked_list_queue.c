#include <stdio.h>
#include <stdlib.h>
#include "linked_list_queue.h"

linked_list_node *create_linked_list_node(int value) {
    linked_list_node *node = malloc(sizeof(linked_list_node));
    node->value = value;
    node->next = NULL;
    return node;
}

linked_list_queue *create_queue(int size) {
    linked_list_queue *queue = malloc(sizeof(linked_list_queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(linked_list_queue *queue, int value) {
    if (!queue) {
        printf("queue not defined\n");
        return;
    }
    linked_list_node *new_node = create_linked_list_node(value);
    if (!queue->front) {
        queue->front = new_node;
        queue->rear = new_node;
        return;
    }
    linked_list_node *last_node = queue->rear;
    last_node->next = new_node;
    queue->rear = new_node;
    return;
}

int dequeue(linked_list_queue *queue) {
    if (is_empty_queue(queue)) {
        printf("queue is empty!!\n");
        return -1;
    }
    int retval;
    if (queue->front == queue->rear) {
        retval = queue->front->value;
        queue->front = NULL;
        queue->rear = NULL;
        return retval;
    }
    linked_list_node *node = queue->front;
    queue->front = node->next;
    retval = node->value;
    free(node);
    return retval;
}

int front(linked_list_queue *queue) {
    if (is_empty_queue(queue)) {
        printf("queue is empty!!\n");
        return -1;
    }
    return queue->front->value;
}

int queue_size(linked_list_queue *queue) {
    if (is_empty_queue(queue)) {
        printf("queue is empty!!\n");
        return -1;
    }
    int count = 0;
    linked_list_node *current = queue->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int is_empty_queue(linked_list_queue *queue) {
    return !queue || !queue->front;
}

void delete_queue(linked_list_queue *queue) {
    if (queue) {
        linked_list_node *current = queue->front;
        while (current) {
            linked_list_node *node = current;
            free(current);
            current = node->next;
        }
        free(queue);
    }
}
