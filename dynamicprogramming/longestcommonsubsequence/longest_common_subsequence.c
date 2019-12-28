#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b)? a : b;
}

int lcs_memo[MAX_SIZE][MAX_SIZE];

int lcs(char *x, char *y, int m, int n) {
    printf("[lcs] x:%s\ty:%s\tm:%d\tn:%d\n", x, y, m, n);
    // A B C B D A B
    // B D C A B A

    if (m == 0 || n == 0) {
        return 0;
    }
    if (x[m-1] == y[n-1]) {
        return 1 + lcs(x, y, m-1, n-1);
    } else {
        return max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
    }
}

void test_longest_common_subsequence() {
    printf("[test] test_longest_common_subsequence started!!\n");

    char *x = "ABCBDAB";
    char *y = "BDCABA";
    int m = strlen(x);
    int n = strlen(y);

    // "BCBA"
    // "BDAB"
    // "BCAB"
    assert( lcs(x, y, m, n) == 4 );

    printf("[test] test_longest_common_subsequence finished!!\n");
}

int main() {

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            lcs_memo[i][j] = 0;
        }
    }

    test_longest_common_subsequence();

    return 0;
}
