#include <stdio.h>
#include <assert.h>
#include "set.h"

void test_set() {
    printf("[test] test set started!!\n");

    set *s = create_set();

    int numbers[] = {7, 5, 8, 4, 0, 9, 1, 7, 3, 6, 2, 3, 5, 7};
    int size = sizeof(numbers) / sizeof(int);

    for (int i = 0; i < size; i++) {
        add_value(s, numbers[i]);
    }

    print_set(s);

    assert( length(s) == 10 );

    for (int i = 0; i < 10; i++) {
        remove_value(s, i);
        assert( length(s) == 9 - i );
    }

    printf("[test] test set finished!!\n");
}

void test_set_union() {
    printf("[test] test set union started!!\n");

    set *s1 = create_set();
    set *s2 = create_set();

    int n1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(n1) / sizeof(int);
    int n2[] = {4, 5, 6, 7, 8};
    int size2 = sizeof(n2) / sizeof(int);

    for (int i = 0; i < size1; i++) add_value(s1, n1[i]);
    for (int i = 0; i < size2; i++) add_value(s2, n2[i]);

    set *s3 = set_union(s1, s2);

    int n3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size3 = sizeof(n3) / sizeof(int);
    for (int i = 0; i < size3; i++) assert( remove_value(s3, n3[i]) == i + 1 );

    printf("[test] test set union finished!!\n");
}

int main() {
    test_set();
    test_set_union();
    return 0;
}
