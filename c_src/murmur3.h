#ifndef C_SRC_MURMUR3_H_
#define C_SRC_MURMUR3_H_

#include <stdlib.h>
#include <stdint.h>

int32_t hash_murmur3_x64_128(const void* key, const int len, const uint32_t seed);

#endif
