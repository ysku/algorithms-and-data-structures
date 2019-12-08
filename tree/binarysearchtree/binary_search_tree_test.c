#include <stdio.h>
#include <assert.h>
#include "binary_search_tree.h"

void test_binary_search_tree() {
    printf("[test] binary search tree started!!\n");
    binary_search_tree *bstree = create_binary_search_tree();

    int numbers[] = {10, 6, 16, 4, 9, 13, 7};
    int size = sizeof(numbers) / sizeof(int);

    for (int i = 0; i < size; i++) {
        binary_search_tree_node *node = insert(&bstree, numbers[i]);
        printf("inserted %d\n", numbers[i]);
        assert( node->value == numbers[i] );
    }

    for (int i = 0; i < size; i++) {
        int target = numbers[i];
        binary_search_tree_node *node = find(bstree, target);
        assert( node->value == target );
        printf("find %d\n", target);
    }

    assert( find(bstree, 8) == NULL );

    printf("[test] binary search tree finished!!\n");
}

int main() {
    test_binary_search_tree();
    return 0;
}
