#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

void test_linked_list() {
    printf("started linked list test!!\n");

    linked_list_node *list = new_linked_list_node(0);
    int n = 10;

    for (int i = 1; i < n; i++) {
        insert(list, i);
    }

    assert( length(list) == n );

    for (int i = 0; i < n; i++) {
        assert( get(list, 0)->value == 0 );
    }

    assert( delete_node(list, 5)->value == 5 );

    assert( length(list) == 9 );

    assert( pop(&list)->value == 0 );

    assert( length(list) == 8 );

    printf("finished linked list test!!\n");
}

int main(void) {
    test_linked_list();
}
