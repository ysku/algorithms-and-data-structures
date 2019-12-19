#include <stdio.h>
#include <assert.h>
#include "openaddress_hash.h"

int main() {
    printf("[test] test open address hash started!!\n");

    openaddress_hash *hash = create_hash(INIT_HASH_SIZE);

    print_hash(hash);

    hash_insert(&hash, "key0", "value0");
    hash_insert(&hash, "key1", "value1");
    hash_insert(&hash, "key2", "value2");
    hash_insert(&hash, "key3", "value3");
    hash_insert(&hash, "key4", "value4");
    hash_insert(&hash, "key5", "value5");
    hash_insert(&hash, "key6", "value6");
    hash_insert(&hash, "key7", "value7");
    hash_insert(&hash, "key8", "value8");
    hash_insert(&hash, "key9", "value9");
    hash_insert(&hash, "key10", "value10");
    hash_insert(&hash, "key11", "value11");
    hash_insert(&hash, "key12", "value12");
    hash_insert(&hash, "key13", "value13");
    hash_insert(&hash, "key14", "value14");
    hash_insert(&hash, "key15", "value15");

    printf("finish insert\n");
    print_hash(hash);

    assert( hash->count == 16 );

    assert( hash_search(hash, "key0")->value == "value0" );
    assert( hash_search(hash, "key1")->value == "value1" );
    assert( hash_search(hash, "key2")->value == "value2" );
    assert( hash_search(hash, "key3")->value == "value3" );
    assert( hash_search(hash, "key4")->value == "value4" );
    assert( hash_search(hash, "key5")->value == "value5" );
    assert( hash_search(hash, "key6")->value == "value6" );
    assert( hash_search(hash, "key7")->value == "value7" );
    assert( hash_search(hash, "key8")->value == "value8" );
    assert( hash_search(hash, "key9")->value == "value9" );
    assert( hash_search(hash, "key10")->value == "value10" );
    assert( hash_search(hash, "key11")->value == "value11" );
    assert( hash_search(hash, "key12")->value == "value12" );
    assert( hash_search(hash, "key13")->value == "value13" );
    assert( hash_search(hash, "key14")->value == "value14" );
    assert( hash_search(hash, "key15")->value == "value15" );

    hash_delete(hash, "key1");
    hash_delete(hash, "key3");
    hash_delete(hash, "key5");
    hash_delete(hash, "key7");
    hash_delete(hash, "key9");
    hash_delete(hash, "key11");
    hash_delete(hash, "key13");
    hash_delete(hash, "key15");

    assert( hash->count == 8 );

    printf("finish delete\n");
    print_hash(hash);

    delete_hash(hash);
    printf("finish delete hash itself\n");

    printf("[test] test open address hash finished!!\n");
    return 0;
}
