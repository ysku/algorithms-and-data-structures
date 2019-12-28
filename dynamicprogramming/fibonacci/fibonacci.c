#include <stdio.h>
#include <assert.h>

/*
 * Fib(n) = 0 ( n = 0 の場合 )
 *        = 1 ( n = 1 の場合 )
 *        = Fib(n-1) + Fib(n-2) ( n > 1 の場合 )
 */
int recursive_fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

void test_recursive_fibonacci() {
    printf("[test] test_recursive_fibonacci started!!\n");

    assert( recursive_fibonacci(0) == 0 );
    assert( recursive_fibonacci(1) == 1 );
    assert( recursive_fibonacci(2) == 1 );
    assert( recursive_fibonacci(3) == 2 );
    assert( recursive_fibonacci(4) == 3 );
    assert( recursive_fibonacci(5) == 5 );
    assert( recursive_fibonacci(6) == 8 );
    assert( recursive_fibonacci(7) == 13 );

    printf("[test] test_recursive_fibonacci finished!!\n");
}

int bottom_up_fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int bottom_up_fib[n + 1];

    bottom_up_fib[0] = 0;
    bottom_up_fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        bottom_up_fib[i] = bottom_up_fib[i - 1] + bottom_up_fib[i - 2];
    }
    return bottom_up_fib[n];
}

void test_button_up_fibonacci() {
    printf("[test] test_button_up_fibonacci started!!\n");

    assert( bottom_up_fib(0) == 0 );
    assert( bottom_up_fib(1) == 1 );
    assert( bottom_up_fib(2) == 1 );
    assert( bottom_up_fib(3) == 2 );
    assert( bottom_up_fib(4) == 3 );
    assert( bottom_up_fib(5) == 5 );
    assert( bottom_up_fib(6) == 8 );
    assert( bottom_up_fib(7) == 13 );

    printf("[test] test_button_up_fibonacci finished!!\n");
}

int top_down_fib[100];
int top_down_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (top_down_fib[n] != 0) return top_down_fib[n];
    top_down_fib[n] = top_down_fibonacci(n-1) + top_down_fibonacci(n-2);
    return top_down_fib[n];
}

void test_top_down_fibonacci() {
    printf("[test] test_top_down_fibonacci started!!\n");

    for (int i = 0; i < 100; i++) top_down_fib[i] = 0;

    assert( top_down_fibonacci(0) == 0 );
    assert( top_down_fibonacci(1) == 1 );
    assert( top_down_fibonacci(2) == 1 );
    assert( top_down_fibonacci(3) == 2 );
    assert( top_down_fibonacci(4) == 3 );
    assert( top_down_fibonacci(5) == 5 );
    assert( top_down_fibonacci(6) == 8 );
    assert( top_down_fibonacci(7) == 13 );

    printf("[test] test_top_down_fibonacci finished!!\n");
}

int main() {
    test_recursive_fibonacci();

    test_button_up_fibonacci();

    test_top_down_fibonacci();

    return 0;
}