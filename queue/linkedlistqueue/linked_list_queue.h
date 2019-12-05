#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

typedef struct linked_list_node_tag linked_list_node;

struct linked_list_node_tag {
    int value;
    linked_list_node *next;
};

linked_list_node *create_linked_list_node(int value);

typedef struct linked_list_queue {
    linked_list_node *front;
    linked_list_node *rear;
} linked_list_queue;

linked_list_queue *create_queue(int size);

void enqueue(linked_list_queue *queue, int value);

int dequeue(linked_list_queue *queue);

int front(linked_list_queue *queue);

int queue_size(linked_list_queue *queue);

int is_empty_queue(linked_list_queue *queue);

void delete_queue(linked_list_queue *queue);

#endif
