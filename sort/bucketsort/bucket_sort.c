#include <stdio.h>
#include <stdlib.h>
#include "bucket_sort.h"

Entry *create_entry(int element) {
    Entry *entry = malloc(sizeof(Entry));
    if (entry == NULL) {
        fprintf(stderr, "memory error!!\n");
        return NULL;
    }
    entry->element = element;
    entry->next = NULL;
    return entry;
}

void print_entry(Entry *entry) {
    printf("[entry] element:%d\n", (int)entry->element);
}

Bucket *create_bucket(int size) {
    Bucket *bucket = malloc(sizeof(Bucket));
    if (bucket == NULL) {
        fprintf(stderr, "memory error!!\n");
        return NULL;
    }
    bucket->size = size;
    bucket->head = NULL;
    return bucket;
}

int compare(Entry *e1, Entry *e2) {
    if (e1->element == e2->element) {
        return 0;
    } else if (e1->element > e2->element) {
        return 1;
    } else {
        return -1;
    }
}

void print_bucket(Bucket *bucket) {
    printf(" === bucket === \n");
    printf(" size: %d\n", bucket->size);
    Entry *current = bucket->head;
    while (current != NULL) {
        print_entry(current);
        current = current->next;
    }
    printf(" ============== \n");
}

void insert_entry(Bucket *bucket, Entry *entry) {
    if (bucket->head == NULL) {
        bucket->head = entry;
        return;
    }
    Entry *current = bucket->head;
    Entry *next = current->next;
    if (compare(entry, current) < 0) {
        entry->next = current;
        bucket->head = entry;
        return;
    }
    while (next != NULL && compare(entry, next) > 0) {
        current = next;
        next = next->next;
    }
    entry->next = next;
    current->next = entry;
}

int *get_sorted_array(Bucket *bucket) {
    int *arr = malloc(sizeof(int) * bucket->size);
    int idx = 0;
    Entry *current = bucket->head;
    while (current != NULL) {
        arr[idx] = current->element;
        current = current->next;
        idx++;
    }
    return arr;
}

int *bucket_sort(int arr[], int n) {
    Bucket *bucket = create_bucket(n);
    for (int i = 0; i < n; i++) {
        Entry *entry = create_entry(arr[i]);
        insert_entry(bucket, entry);
    }
    return get_sorted_array(bucket);
}
