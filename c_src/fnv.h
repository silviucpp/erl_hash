#ifndef C_SRC_FNV_H_
#define C_SRC_FNV_H_

#include <stdlib.h>
#include <stdint.h>

uint32_t hash_fnv1_64(const unsigned char *key, size_t key_length);
uint32_t hash_fnv1a_64(const unsigned char *key, size_t key_length);
uint32_t hash_fnv1_32(const unsigned char *key, size_t key_length);
uint32_t hash_fnv1a_32(const unsigned char *key, size_t key_length);


#endif
