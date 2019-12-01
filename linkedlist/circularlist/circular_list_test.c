#include <stdio.h>
#include <assert.h>
#include "circular_list.h"

void test_circular_list() {
    printf("[circular list] started test!!\n");

    circular_list_node *list = new_circular_list_node(0);
    list->next = list;

    int n = 10;

    for (int i = 1; i < n; i++) {
        insert(list, i);
    }
    printf("[circular list] passed insert test!!\n");

    assert( length(list) == n );
    printf("[circular list] passed length test!!\n");

    for (int i = 0; i < n; i++) {
        assert( get(list, 0)->value == 0 );
    }
    printf("[circular list] passed get test!!\n");

    assert( delete(list, 5)->value == 5 );
    assert( length(list) == 9 );
    printf("[circular list] passed remove test!!\n");

    assert( pop(&list)->value == 0 );
    assert( length(list) == 8 );
    printf("[circular list] passed pop test!!\n");

    printf("[circular list] finished test!!\n");
}

int main(void) {
    test_circular_list();
}
