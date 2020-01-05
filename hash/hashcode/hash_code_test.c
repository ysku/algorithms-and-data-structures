#include <stdio.h>
#include <assert.h>
#include "hash_code.h"

void test_hash_code() {
    printf("[test] test_hash_code started!!\n");

    int h1 = hash_code("abc");
    int h2 = hash_code("def");
    int h3 = hash_code("abc");

    assert( h1 != h2 );
    assert( h2 != h3 );
    assert( h3 == h1 );

    printf("[test] test_hash_code finished!!\n");
}

int main() {
    test_hash_code();

    return 0;
}
