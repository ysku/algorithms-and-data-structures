#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "two_three_four_tree.h"

void test_insert_a_character() {
    printf("[test] test_insert_a_character started\n");

    char characters[] = {'A', 'S', 'E', 'A'};

    node *root = create_node();

    insert_a_character(root, characters[0]);
    assert( strcmp(root->word, "A") == 0 );
    assert( root->count == 1 );

    insert_a_character(root, characters[1]);
    assert( strcmp(root->word, "AS") == 0 );
    assert( root->count == 2 );

    insert_a_character(root, characters[2]);
    assert( strcmp(root->word, "AES") == 0 );
    assert( root->count == 3 );

    insert_a_character(root, characters[3]);
    assert( strcmp(root->word, "AAES") == 0 );
    assert( root->count == 4 );

    delete_node(root);

    printf("[test] test_insert_a_character finished\n");
}

void test_split() {
    printf("[test] test_split started\n");

    char characters[] = {'W', 'A', 'K', 'A'};
    size_t n = sizeof(characters) / sizeof(char);

    node *root = create_node();

    for (size_t i = 0; i < n; i++) {
        insert_a_character(root, characters[i]);
    }

    split(&root);

    assert( strcmp(root->word, "K") == 0 );
    assert( strcmp(root->first->word, "AA") == 0 );
    assert( strcmp(root->second->word, "W") == 0 );

    delete_node(root);

    printf("[test] test_split finished\n");
}

void test_two_three_four_tree_step_by_step() {
    // cf. http://web-ext.u-aizu.ac.jp/course/alg1/ex/jp/ex11/
    printf("[test] test_two_three_four_tree_step_by_step started\n");

    char characters[] = {'W', 'A', 'K', 'A', 'M', 'A', 'T', 'S', 'U', 'N', 'A', 'O', 'K', 'I'};
    size_t n = sizeof(characters) / sizeof(char);

    node *root = create_node();

    printf("[test_two_three_four_tree_step_by_step] %s\n", root->word);

    insert(&root, characters[0]);   // W
    printf("[test_two_three_four_tree_step_by_step] %s\n", root->word);
    assert( strcmp(root->word, "W") == 0 );
    assert( root->count == 1 );

    insert(&root, characters[1]);   // A
    assert( strcmp(root->word, "AW") == 0 );

    insert(&root, characters[2]);   // K
    assert( strcmp(root->word, "AKW") == 0 );

    insert(&root, characters[3]);   // A
    assert( strcmp(root->word, "K") == 0 );
    assert( strcmp(root->first->word, "AA") == 0 );
    assert( strcmp(root->second->word, "W") == 0 );
    assert( strcmp(root->first->parent->word, "K") == 0 );
    assert( strcmp(root->second->parent->word, "K") == 0 );

    insert(&root, characters[4]);   // M
    assert( strcmp(root->word, "K") == 0 );
    assert( strcmp(root->first->word, "AA") == 0 );
    assert( strcmp(root->second->word, "MW") == 0 );
    assert( strcmp(root->first->parent->word, "K") == 0 );
    assert( strcmp(root->second->parent->word, "K") == 0 );

    insert(&root, characters[5]);
    assert( strcmp(root->word, "K") == 0 );
    assert( strcmp(root->first->word, "AAA") == 0 );
    assert( strcmp(root->second->word, "MW") == 0 );
    assert( strcmp(root->first->parent->word, "K") == 0 );
    assert( strcmp(root->second->parent->word, "K") == 0 );

    insert(&root, characters[6]);
    assert( strcmp(root->word, "K") == 0 );
    assert( strcmp(root->first->word, "AAA") == 0 );
    assert( strcmp(root->second->word, "MTW") == 0 );
    assert( strcmp(root->first->parent->word, "K") == 0 );
    assert( strcmp(root->second->parent->word, "K") == 0 );

    insert(&root, characters[7]);   // insert S
    assert( strcmp(root->word, "KT") == 0 );
    assert( strcmp(root->first->word, "AAA") == 0 );
    assert( strcmp(root->second->word, "MS") == 0 );
    assert( strcmp(root->third->word, "W") == 0 );

    insert(&root, characters[8]);
    assert( strcmp(root->word, "KT") == 0 );
    assert( strcmp(root->first->word, "AAA") == 0 );
    assert( strcmp(root->second->word, "MS") == 0 );
    assert( strcmp(root->third->word, "UW") == 0 );

    insert(&root, characters[9]);
    assert( strcmp(root->word, "KT") == 0 );
    assert( strcmp(root->first->word, "AAA") == 0 );
    assert( strcmp(root->second->word, "MNS") == 0 );
    assert( strcmp(root->third->word, "UW") == 0 );

    insert(&root, characters[10]);
    assert( strcmp(root->word, "K") == 0 );
    assert( strcmp(root->first->word, "A") == 0 );
    assert( strcmp(root->second->word, "T") == 0 );

    assert( strcmp(root->first->first->word, "A") == 0 );
    assert( strcmp(root->first->second->word, "AA") == 0 );

    assert( strcmp(root->second->first->word, "MNS") == 0 );
    assert( strcmp(root->second->second->word, "UW") == 0 );

    delete_node(root);

    printf("[test] test_two_three_four_tree_step_by_step finished\n");
}

int main() {
    test_insert_a_character();

    test_split();

    test_two_three_four_tree_step_by_step();

    return 0;
}
