#include <stdio.h>
#include <assert.h>
#include "linked_list_queue.h"

void test_queue() {
    printf("[test] start queue testing\n");

    int size = 10;
    linked_list_queue *queue = create_queue(size);

    assert( is_empty_queue(queue) == 1 );
    printf("[test] pass is_empty_queue \n");

    for (int i = 0; i < size; i++) {
        enqueue(queue, i);
    }
    printf("[test] pass enqueue \n");

    assert( queue_size(queue) == 10 );
    printf("[test] pass queue_size \n");

    assert( front(queue) == 0 );
    printf("[test] pass front \n");

    for (int i = 0; i < size; i++) {
        assert( dequeue(queue) == i );
    }
    assert( dequeue(queue) == -1 ); // queue underflow
    printf("[test] pass dequeue \n");

    delete_queue(queue);
    printf("[test] pass delete_queue \n");

    printf("[test] finish queue testing\n");
}

int main(void) {
    test_queue();
    return 0;
}
