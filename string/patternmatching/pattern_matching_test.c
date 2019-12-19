#include <stdio.h>
#include <assert.h>
#include "pattern_matching.h"

typedef struct {
    char *given;
    char *pattern;
    size_t n;
    size_t m;
    bool expected;
} test_case;

test_case test_case_1 = {
    "We introduce a general framework which is suitable to capture an essence of compressed pattern matching according to various dictionary based compressions.",
    "compress",
    155,
    8,
    true
};

test_case test_case_2 = {
    "abcdefghij",
    "ij",
    10,
    2,
    true
};

test_case test_case_3 = {
    "computerscience",
    "entrance",
    15,
    8,
    false
};

void execute_test_case(test_case t, bool (*func)(char *pattern, size_t m, char *text, size_t n)) {
    printf("pattern : %s, text : %s\n", t.pattern, t.given);
    assert( func(t.pattern, t.m, t.given, t.n) == t.expected );
}

void test_brute_force() {
    printf("[test] test brute force started!!\n");

    execute_test_case(test_case_1, brute_force);
    execute_test_case(test_case_2, brute_force);
    execute_test_case(test_case_3, brute_force);

    printf("[test] test brute force finished!!\n");
}

void test_rabin_karp() {
    printf("[test] test rabin_karp started!!\n");

    execute_test_case(test_case_1, rabin_karp);
    execute_test_case(test_case_2, rabin_karp);
    execute_test_case(test_case_3, rabin_karp);

    printf("[test] test rabin_karp finished!!\n");
}

int main() {
    test_brute_force();

    test_rabin_karp();

    return 0;
}
