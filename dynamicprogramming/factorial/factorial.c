#include <stdio.h>
#include <assert.h>

/*
 * factorial(n) = 1 ( n = 0 の場合 )
 *              = n * factorial(n-1) ( n >= 1 の場合 )
 */
int recursive_factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * recursive_factorial(n-1);
}

void test_recursive_factorial() {
    printf("[test] test_recursive_factorial started!!\n");

    assert( recursive_factorial(0) == 1 );
    assert( recursive_factorial(1) == 1 );
    assert( recursive_factorial(2) == 2 );
    assert( recursive_factorial(3) == 6 );
    assert( recursive_factorial(4) == 24 );
    assert( recursive_factorial(5) == 120 );
    assert( recursive_factorial(6) == 720 );
    assert( recursive_factorial(7) == 5040 );

    printf("[test] test_recursive_factorial finished!!\n");
}

int bottom_up_factorial(int n) {
    if (n == 0) return 1;

    int bottom_up_fact[n + 1];

    bottom_up_fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        bottom_up_fact[i] = i * bottom_up_fact[i - 1];
    }
    return bottom_up_fact[n];
}

void test_bottom_up_factorial() {
    printf("[test] test_bottom_up_factorial started!!\n");

    assert( bottom_up_factorial(0) == 1 );
    assert( bottom_up_factorial(1) == 1 );
    assert( bottom_up_factorial(2) == 2 );
    assert( bottom_up_factorial(3) == 6 );
    assert( bottom_up_factorial(4) == 24 );
    assert( bottom_up_factorial(5) == 120 );
    assert( bottom_up_factorial(6) == 720 );
    assert( bottom_up_factorial(7) == 5040 );

    printf("[test] test_bottom_up_factorial finished!!\n");
}

int top_down_fact[100];
int top_down_factorial(int n) {
    if (n == 0) return 1;
    if (top_down_fact[n] != 0) return top_down_fact[n];
    top_down_fact[n] = n * top_down_factorial(n-1);
    return top_down_fact[n];
}

void test_top_down_factorial() {
    printf("[test] test_top_down_factorial started!!\n");

    for (int i = 0; i < 100; i++) top_down_fact[i] = 0;

    assert( top_down_factorial(0) == 1 );
    assert( top_down_factorial(1) == 1 );
    assert( top_down_factorial(2) == 2 );
    assert( top_down_factorial(3) == 6 );
    assert( top_down_factorial(4) == 24 );
    assert( top_down_factorial(5) == 120 );
    assert( top_down_factorial(6) == 720 );
    assert( top_down_factorial(7) == 5040 );

    printf("[test] test_top_down_factorial finished!!\n");
}

int main() {
    test_recursive_factorial();

    test_bottom_up_factorial();

    test_top_down_factorial();

    return 0;
}
