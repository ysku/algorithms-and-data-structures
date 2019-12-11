#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

avl_tree_node *create_avl_tree_node(int value) {
    avl_tree_node *node = malloc(sizeof(avl_tree_node));
    if (!node) {
        printf("memory error!!\n");
        return NULL;
    }
    node->value = value;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(avl_tree_node *node) {
    if (!node) return 0;

    int left_height, right_height;
    if (node->left) left_height = height(node->left);
    else left_height = 0;

    if (node->right) right_height = height(node->right);
    else right_height = 0;

    if (left_height > right_height) return left_height + 1;
    else return right_height + 1;
}

int is_balanced(avl_tree_node *node) {
    // +2 : single rotate right
    // -2 : single rotate left
    return height(node->right) - height(node->left);
}

avl_tree *create_avl_tree() {
    avl_tree *tree = malloc(sizeof(avl_tree));
    if (!tree) {
        printf("memory error!!\n");
        return NULL;
    }
    tree->root = NULL;
    tree->height = 0;
    return tree;
}

const int QUEUE_SIZE = 100;

typedef struct {
    int front;
    int rear;
    avl_tree_node *arr[QUEUE_SIZE];
} queue;

queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    if (!q) {
        printf("memory error!!\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty_queue(queue *q) {
    if (!q) return 1;
    return q->front == -1;
}

int is_full_queue(queue *q) {
    return (q->rear - q->front) == QUEUE_SIZE - 1;
}

void enqueue(queue *q, avl_tree_node *node) {
    if (is_full_queue(q)) {
        printf("queue overflow!!\n");
        return;
    }
    if (is_empty_queue(q)) {
        q->front = q->rear = 0;
        q->arr[0] = node;
        return;
    } else {
        q->arr[++q->rear] = node;
    }
}

avl_tree_node *dequeue(queue *q) {
    if (is_empty_queue(q)) {
        printf("queue underflow!!\n");
        return NULL;
    }
    avl_tree_node *node = q->arr[q->front];
    if (q->front == q->rear) {
        q->rear = q->front = -1;
    } else {
        q->front++;
    }
    return node;
}

void display_tree(avl_tree *tree) {
    avl_tree_node *current = tree->root;
    queue *q = create_queue();
    enqueue(q, current);
    printf(" === display_tree === \n");
    while (!is_empty_queue(q)) {
        current = dequeue(q);
        printf("node : %d\n", current->value);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
    printf(" === end of display_tree === \n");
}

void single_rotate_left(avl_tree_node **node) {
    avl_tree_node *current = (*node);
    avl_tree_node *left = current->left;
    current->left = left->right;
    left->right = current;
    *node = left;
}

void single_rotate_right(avl_tree_node **node) {
    avl_tree_node *current = (*node);
    avl_tree_node *right = current->right;
    current->right = right->left;
    right->left = current;
    *node = right;
}

void double_rotate_with_left(avl_tree_node **node) {
    avl_tree_node **left = &((*node)->left);
    single_rotate_right(left);
    single_rotate_left(node);
}

void double_rotate_with_right(avl_tree_node **node) {
    printf("double rotate with right \n");
    avl_tree_node **right = &((*node)->right);
    single_rotate_left(right);
    single_rotate_right(node);
}

void insert(avl_tree *tree, int value) {
    avl_tree_node *new_node = create_avl_tree_node(value);
    if (!tree->root) {
        new_node->height = 1;
        tree->root = new_node;
        return;
    }
    avl_tree_node **prev_prev = NULL;
    avl_tree_node **prev = NULL;
    avl_tree_node **current = &(tree->root);
    while (1) {
        if ((*current)->value == new_node->value) {
            printf("value (%d) already exists\n", new_node->value);
            return;
        } else if ((*current)->value > new_node->value) {
            if ((*current)->left == NULL) {
                new_node->height = (*current)->height + 1;
                (*current)->left = new_node;
                if (prev != NULL && height((*prev)->left) - height((*prev)->right) == 2) {
                    if (value < (*prev)->left->value) single_rotate_left(prev);
                    else double_rotate_with_left(prev_prev);
                } else if (prev_prev != NULL && height((*prev_prev)->right) - height((*prev_prev)->left) == 2) {
                    double_rotate_with_right(prev_prev);
                }
                return;
            }
            prev_prev = prev;
            prev = current;
            current = &((*current)->left);
        } else {
            if ((*current)->right == NULL) {
                new_node->height = (*current)->height + 1;
                (*current)->right = new_node;
                if (prev != NULL && height((*prev)->right) - height((*prev)->left) == 2) {
                    if (value > (*prev)->right->value) single_rotate_right(prev);
                    else double_rotate_with_right(prev_prev);
                } else if (prev_prev != NULL && height((*prev_prev)->left) - height((*prev_prev)->right) == 2) {
                    double_rotate_with_left(prev_prev);
                }
                return;
            }
            prev_prev = prev;
            prev = current;
            current = &((*current)->right);
        }
    }
}
