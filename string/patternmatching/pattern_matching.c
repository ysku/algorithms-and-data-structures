#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pattern_matching.h"

bool brute_force(char *pattern, size_t m, char *text, size_t n) {
    for (size_t i = 0; i < n; i++) {
        size_t j = 0;
        while (j < m && pattern[j] == text[i + j]) {
            j++;
        }
        if (j == m) {
            return true;
        }
    }
    return false;
}

void substr(char *result, char *src, size_t s, size_t e) {
    size_t len = e - s;
    strncpy(result, src+s, len);
    result[len] = '\0';
}

size_t hash(char *word) {
    // sdbm
    size_t hashAddress = 0;
    for (size_t counter = 0; word[counter] != '\0'; counter++){
        hashAddress = word[counter] + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
    }
    return hashAddress;
}

bool rabin_karp(char *pattern, size_t m, char *text, size_t n) {
    // P のハッシュと T の m 文字のハッシュが同じ結果になる場合にだけ調べる
    // 計算量は O(m + n) になる
    char parts[m];
    size_t hp = hash(pattern);
    for (size_t i = 0; i < n; i++) {
        substr(parts, text, i, m+i);
        size_t ht = hash(parts);
        if (hp == ht && strcmp(parts, pattern) == 0) {
            return true;
        }
    }
    return false;
}
