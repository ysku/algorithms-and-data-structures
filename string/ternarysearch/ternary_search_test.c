#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "ternary_search.h"

void test_ternary_search_tree() {
    printf("[test] test ternary search tree started!!\n");

    char *words[] = {
            "c",
            "cpp",
            "ruby",
            "java",
            "python",
            "javascript",
            "php",
            "swift",
            "objective-c",
            "perl",
            "groovy",
            "dart",
            "scala",
            "rust",
            "lua",
            "julia",
            "scheme",
            "elixir",
            "erlang",
            "golang"
    };

    size_t n = 20;

    tst_node *root = create_tst_node();

    for (size_t i = 0; i < n; i++) {
        insert(root, words[i]);
    }

    printf("finish inserting words\n");

    display_tst_node(root);
    display_tst_node(root->eq);
    display_tst_node(root->eq->right);
    display_tst_node(root->eq->right->eq);
    display_tst_node(root->right);

    for (size_t i = 0; i < n; i++) {
        assert( search(root, words[i]) );
    }

    printf("finish searching existing words\n");

    assert( !search(root, "ada") );
    assert( !search(root, "lisp") );
    assert( !search(root, "kotlin") );
    assert( !search(root, "scratch") );
    assert( !search(root, "cobol") );

    printf("finish searching non-existing words\n");

    printf("[test] test ternary search tree finished!!\n");
}

int main() {
    test_ternary_search_tree();

    return 0;
}
