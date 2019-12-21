#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "trie.h"

#define NUMBER_OF_WORDS (354935)
#define INPUT_WORD_SIZE (100)

void test_trie() {
    printf("[test] test trie started!!\n");

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

    trie_node *root = create_trie_node();

    for (size_t i = 0; i < n; i++) {
        insert(root, words[i]);
    }

    printf("finish inserting words\n");

    printf("here : %c\n", root->children['c'-97]->character);
    printf("here : %c\n", root->children['c'-97]->children['p'-97]->character);
    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        printf("iterating");
        if (root->children['c'-97]->children['p'-97]->children[i] != NULL) {
            printf("[here] %c\n", root->children['c'-97]->children['p'-97]->children[i]->character);
        }
    }
    printf("here : %c\n", root->children['c'-97]->children['p'-97]->children['p'-97]->character);

    for (size_t i = 0; i < n; i++) {
        assert( search(root, words[i]) );
    }

    printf("finish searching exist words\n");

    assert( !search(root, "ada") );
    assert( !search(root, "lisp") );
    assert( !search(root, "kotlin") );
    assert( !search(root, "scratch") );
    assert( !search(root, "cobol") );

    printf("[test] test trie finished!!\n");
}

int main() {
    test_trie();

    return 0;
}
