#ifndef _2-CHOICE_HASH_H_INCLUDED
#define _2-CHOICE_HASH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "hash.h"

#define KEY_LEN 10
#define VALUE_LEN 10

typedef struct hash_node
{
    uint8_t key[KEY_LEN];
    uint8_t value[VALUE_LEN];
    uint8_t token;
}hash_node;

typedef struct _2choice_hash
{
    uint32_t max_capacity;
    uint32_t num_total_element;
    uint64_t seed;
    hash_node *node;
}_2choice_hash;


_2choice_hash* _2choice_init(uint32_t size);
uint8_t _2choice_insert(_2choice_hash *_2choice, uint8_t *key, uint8_t *value);
uint8_t* _2choice_query(_2choice_hash *_2choice, uint8_t *key);
uint8_t _2choice_delete(_2choice_hash *_2choice, uint8_t *key);
uint8_t _2choice_destory(_2choice_hash *_2choice);


#endif // _2-CHOICE_HASH_H_INCLUDED
