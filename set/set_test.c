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

int main() {
    test_set();
    return 0;
}
