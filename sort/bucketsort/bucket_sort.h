#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

typedef struct entry_tag Entry;

struct entry_tag {
    int element;
    Entry *next;
};

Entry *create_entry(int element);

typedef struct {
    int size;
    Entry *head;
} Bucket;

Bucket *create_bucket(int size);

int *bucket_sort(int arr[], int n);

#endif
