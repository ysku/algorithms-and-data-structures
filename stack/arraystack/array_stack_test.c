#include <stdio.h>
#include <assert.h>
#include "array_stack.h"

void test_stack() {
    printf("[test] start stack testing\n");

    int size = 10;
    array_stack *stack = create_stack(size);

    assert( is_empty_stack(stack) == 1 );
    printf("[test] pass is_empty_stack \n");

    for (int i = size - 1; i >= 0; i--) {
        push(stack, i);
    }
    printf("[test] pass push \n");

    assert( length(stack) == 10 );
    printf("[test] pass length \n");

    assert( is_full_stack(stack) == 1 );
    printf("[test] pass is_full_stack \n");

    for (int i = 0; i < size; i++) {
        assert( pop(stack) == i );
    }
    assert( pop(stack) == -1 ); // stack underflow
    printf("[test] pass pop \n");

    delete_stack(stack);
    printf("[test] pass delete_stack \n");

    printf("[test] finish stack testing\n");
}

int main(void) {
    test_stack();
    return 0;
}
