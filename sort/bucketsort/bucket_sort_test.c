#include <stdio.h>
#include <assert.h>
#include "bucket_sort.h"

void test_bucket_sort() {
    printf("[test] test_bucket_sort started!!\n");

    int given[] = {7, 5, 13, 2, 14, 1, 6};
    int n = sizeof(given) / sizeof(int);

    int *actual = bucket_sort(given, n);
    int expected[] = {1, 2, 5, 6, 7, 13, 14};

    for (int i = 0; i < n; i++) {
        assert( actual[i] == expected[i] );
    }

    printf("[test] test_bucket_sort finished!!\n");
}

int main() {
    test_bucket_sort();

    return 0;
}
