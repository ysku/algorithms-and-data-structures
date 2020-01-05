#include <stdio.h>
#include <assert.h>
#include "bloom_filter.h"

void test_bloom_filter() {
    printf("[test] test_bloom_filter started!!\n");

    bloom_filter *bf = create_bloom_filter();
    add(bf, hash_code, "abc");
    add(bf, hash_code, "def");
    add(bf, hash_code, "ghi");

    assert( contains(bf, "abc") );
    assert( !contains(bf, "bcd") );
    assert( !contains(bf, "cde") );
    assert( contains(bf, "def") );
    assert( !contains(bf, "efg") );
    assert( !contains(bf, "fgh") );
    assert( contains(bf, "ghi") );

    printf("[test] test_bloom_filter finished!!\n");
}

int main() {
    test_bloom_filter();

    return 0;
}
