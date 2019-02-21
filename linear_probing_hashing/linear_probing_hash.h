#ifndef LINEAR_PROBING_HASH_H_INCLUDED
#define LINEAR_PROBING_HASH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#include "hash.h"

#define KEY_LEN 10
#define VALUE_LEN 10

typedef struct hash_node
{
    uint8_t token;
    uint8_t key[KEY_LEN];
    uint8_t value[VALUE_LEN];
}hash_node;

typedef struct linear_hash
{
    uint32_t num_total_element;
    uint32_t max_capacity;
    uint64_t seed;
    hash_node *node;
}linear_hash;


linear_hash* linear_init(uint32_t size);
uint8_t* linear_query(linear_hash *linear, uint8_t *key);
uint8_t linear_insert(linear_hash *linear, uint8_t *key, uint8_t *value);
uint8_t linear_delete(linear_hash *linear, uint8_t *key);
uint8_t linear_destory(linear_hash *linear);


#endif // LINEAR_PROBING_HASH_H_INCLUDED
