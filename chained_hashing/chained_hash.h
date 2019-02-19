#ifndef CHAINED_HASH_H_INCLUDED
#define CHAINED_HASH_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "hash.h"

#define KEY_LEN 10
#define VALUE_LEN 10

typedef struct chained_node
{
    uint8_t key[KEY_LEN];
    uint8_t value[VALUE_LEN];
    struct chained_node* next;

}chained_node;

typedef struct chained_hash
{
    uint32_t num_total_element;
    uint32_t num_bucket;
    uint64_t seed;
    chained_node** buckets;

}chained_hash;

chained_hash* chained_init(uint32_t num_bucket);
uint8_t* chained_query(chained_hash *chain, uint8_t *key);
uint8_t chained_insert(chained_hash *chain, uint8_t *key, uint8_t*value);
uint8_t chained_delete(chained_hash *chain, uint8_t *key);
uint8_t chained_destory(chained_hash *chain);

#endif // CHAINED_HASH_H_INCLUDED
