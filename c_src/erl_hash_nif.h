#ifndef C_SRC_ERL_HASH_NIF_H_
#define C_SRC_ERL_HASH_NIF_H_

#include "erl_nif.h"

struct atoms
{
    ERL_NIF_TERM atomError;
    ERL_NIF_TERM atomBadArg;
};

extern atoms ATOMS;

#endif
