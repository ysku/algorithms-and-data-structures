#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#define SWAP(type,a,b) { type tmp = a; a = b; b = tmp; }

void shuffle(size_t *arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        size_t j = rand() % n;
        SWAP(size_t, arr[i], arr[j]);
    }
}

void find_largest_in_array(size_t *arr, size_t n) {
    size_t max = 0;
    for (size_t i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    printf("[find_largest_in_array] max : %zu\n", max);
}

void find_smallest_and_largest_in_array(size_t *arr, size_t n) {
    // O(n)
    size_t min = arr[0];
    size_t max = arr[0];
    for (size_t i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        } else if (min > arr[i]) {
            min = arr[i];
        }
    }
    printf("[find_smallest_and_largest_in_array] min : %zu, max : %zu\n", min, max);
}

void find_with_pair_comparison(size_t *arr, size_t n) {
    size_t large = arr[0];
    size_t small = arr[0];
    for (size_t i = 0; i < n; i = i + 2) {
        if (arr[i] < arr[i+1]) {
            if (arr[i] < small) {
                small = arr[i];
            } else if (arr[i+1] > large) {
                large = arr[i+1];
            }
        } else {
            if (arr[i+1] < small) {
                small = arr[i+1];
            }
            if (arr[i] > large) {
                large = arr[i];
            }
        }
    }
    printf("[find_with_pair_comparison] small : %zu, large : %zu\n", small, large);
}

void find_second_largest(size_t *arr, size_t n) {
    size_t first = arr[0];
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > first) {
            first = arr[i];
        }
    }
    size_t second = arr[0] != first ? arr[0] : arr[1];
    for (size_t i = 0; i < n; i++) {
        if (arr[i] != first && arr[i] > second) {
            second = arr[i];
        }
    }
    printf("[find_second_largest] second largest : %zu\n", second);
}

void print_array(size_t *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%zu ", arr[i]);
    }
    printf("\n");
}

int main() {
    size_t n = 100;
    size_t arr[n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = i;
    }
    shuffle(arr, n);
    printf(" *** shuffled array *** \n");
    print_array(arr, n);

    find_largest_in_array(arr, n);

    find_smallest_and_largest_in_array(arr, n);

    find_with_pair_comparison(arr, n);

    find_second_largest(arr, n);

    return 0;
}
