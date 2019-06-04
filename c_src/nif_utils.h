#ifndef C_SRC_NIF_UTILS_H_
#define C_SRC_NIF_UTILS_H_

#include "erl_nif.h"

ERL_NIF_TERM make_atom(ErlNifEnv* env, const char* name);
ERL_NIF_TERM make_badarg(ErlNifEnv* env);
bool get_binary(ErlNifEnv* env, ERL_NIF_TERM term, ErlNifBinary* bin);

#endif
