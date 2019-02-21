#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdint.h>

uint64_t hash(const void *data, uint64_t length, uint64_t seed);

#endif // HASH_H_INCLUDED
