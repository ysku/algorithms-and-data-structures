#include "huffman_coding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *create_node(char character) {
    node *n = malloc(sizeof(node));
    if (!n) {
        printf("memory error!!\n");
        return NULL;
    }
    n->character = character;
    n->repetition = 0;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert_node(node **root, node *entry) {
    printf("[insert_node] root : %zu, entry %c : %zu\n", (*root)->repetition, entry->character, entry->repetition);
    if (!(*root)->left) {
        (*root)->left = entry;
        (*root)->repetition = entry->repetition;
        return;
    }

    node *tmp = (*root);
    while (tmp->left) {
        if (tmp->repetition <= entry->repetition && tmp->right == NULL) {
            tmp->repetition += entry->repetition;
            tmp->right = entry;
            return;
        } else if (tmp->right != NULL && tmp->right->repetition <= entry->repetition) {
            node *new_node = create_node('\0');
            new_node->repetition = tmp->repetition + entry->repetition;
            new_node->left = tmp;
            new_node->right = entry;
            *root = new_node;
            return;
        }
        tmp = tmp->left;
    }
}

void update_huffman_code(node *root) {
    if (!root) {
        printf("empty huffman tree!!\n");
        return;
    }
    char buffer[5];
    buffer[0] = '\0';
    while (root->right) {
        root->right->code = malloc(strlen(buffer) + 1 + 1); // for 1 and '\0'

        strcpy(root->right->code, buffer);
        root->right->code[strlen(buffer)] = '1';
        root->right->code[strlen(buffer)+1] = '\0';

        strcat(buffer, "0");
        printf("c:%c\tcode: %s\n", root->right->character, root->right->code);
        root = root->left;
    }
    root->code = malloc(strlen(buffer) + 1); // for '\0'
    strcpy(root->code, buffer);
    root->code[strlen(buffer)] = '\0';
    printf("c:%c\tcode: %s\n", root->character, root->code);
}

void print_node(node *root) {
    if (root->code) {
        printf("character:%c\trepetition:%zu\tcode:%s\n", root->character, root->repetition, root->code);
    } else {
        printf("character:%c\trepetition:%zu\n", root->character, root->repetition);
    }
}

void display(node *root) {
    while (1) {
        if (root == NULL) {
            return;
        }
        print_node(root);
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        if (root->right) {
            print_node(root);
        }
        if (root->left) {
            print_node(root);
        }
        root = root->left;
    }
}

const int HASH_SIZE = 10;

typedef struct {
    size_t capacity;
    size_t count;
    node *arr[HASH_SIZE];
} hash;

hash *create_hash() {
    hash *h = malloc(sizeof(hash));
    if (!h) {
        goto memory_error;
    }
    h->capacity = HASH_SIZE;
    h->count = 0;
    for (size_t i = 0; i < h->capacity; i++) {
        h->arr[i] = NULL;
    }
    return h;
memory_error:
    printf("memory error!!\n");
    return NULL;
}

size_t hashing(hash *h, char key) {
    int sum = 0;
    int i = 0;
    return key % h->capacity;
}

void hash_insert(hash *h, char key, node *n) {
    size_t hashed = hashing(h, key);
    if (h->arr[hashed]) {
        node *tmp = h->arr[hashed];
        tmp->repetition++;
        h->arr[hashed] = tmp;
    } else {
        n->repetition++;
        h->arr[hashed] = n;
        h->count++;
    }
}

void *hash_get(hash *h, char key) {
    size_t hashed = hashing(h, key);
    return h->arr[hashed];
}

void display_hash(hash *h) {
    for (size_t i = 0; i < h->capacity; i++) {
        if (h->arr[i]) {
            printf("key: %zu, value: %c, repetition: %zu\n", i, h->arr[i]->character, h->arr[i]->repetition);
        }
    }
}

void sort_node_list(node *node_list[], size_t n) {
    // 単純に最小の値を見つける
    for (size_t i = 0; i < n - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n; j++) {
            if (node_list[min]->repetition > node_list[j]->repetition) {
                min = j;
            }
        }
        if (min != i) {
            node *tmp = node_list[min];
            node_list[min] = node_list[i];
            node_list[i] = tmp;
        }
    }
    for (size_t i = 0; i < n; i++) {
        printf("[sort_node_list] %c, repetition: %zu\n", node_list[i]->character, node_list[i]->repetition);
    }
}

char *huffman_coding(char *s) {
    printf("[huffman_coding] : %s\n", s);
    size_t len = strlen(s);

    // 各文字の出現回数をカウント
    hash *h = create_hash();
    for (size_t i = 0; i < len; i++) {
        node *n = create_node(s[i]);
        hash_insert(h, n->character, n);
    }
    int num_of_char = h->count;

    // ハッシュからリストに変換
    node *node_list[num_of_char];
    size_t counter = 0;
    for (size_t i = 0; i < len; i++) {
        if (h->arr[i]) {
            node_list[counter++] = h->arr[i];
        }
    }

    // 各エントリを小さい順に並び替える
    sort_node_list(node_list, num_of_char);

    // ハフマン木の作成
    node *root = create_node('\0');
    for (size_t i = 0; i < num_of_char; i++) {
        insert_node(&root, node_list[i]);
    }

    // 各文字のハフマン符号を取得
    update_huffman_code(root);
}
