#include <assert.h>
#include "priority_queue.h"

void test_priority_queue() {
    printf("[test] priority queue test started!!\n");

    heap *h = create_heap(100);

    int numbers[] = {31, 10, 16, 9, 8, 14, 12, 3, 1, 5, 7, 19};
    int size = sizeof(numbers) / sizeof(int);

    for (int i = 0; i < size; i++) {
        enqueue(h, numbers[i]);
    }

    display(h);

    int results[] = {31, 19, 16, 14, 12, 10, 9, 8, 7, 5, 3, 1};

    for (int i = 0; i < size; i++) {
        int value = dequeue(h);
        assert( value == results[i] );
    }

    printf("[test] priority queue test finished!!\n");
}

int main() {
    test_priority_queue();
    return 0;
}
