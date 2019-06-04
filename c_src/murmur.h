#ifndef C_SRC_MURMUR_H_
#define C_SRC_MURMUR_H_

#include <stdlib.h>
#include <stdint.h>

uint32_t hash_murmur2(const unsigned char *key, size_t length);

#endif
