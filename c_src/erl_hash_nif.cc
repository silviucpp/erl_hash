#include "erl_hash_nif.h"
#include "nif_utils.h"
#include "macros.h"
#include "murmur2.h"
#include "murmur3.h"
#include "fnv.h"

const char kAtomError[] = "error";
const char kAtomBadArg[] = "badarg";

atoms ATOMS;

int on_nif_load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info)
{
    UNUSED(load_info);

    ATOMS.atomError = make_atom(env, kAtomError);
    ATOMS.atomBadArg = make_atom(env, kAtomBadArg);

    *priv_data = NULL;
    return 0;
}

void on_nif_unload(ErlNifEnv* env, void* priv_data)
{
    UNUSED(env);
    UNUSED(priv_data);
}

int on_nif_upgrade(ErlNifEnv* env, void** priv, void** old_priv, ERL_NIF_TERM info)
{
    UNUSED(env);
    UNUSED(old_priv);
    UNUSED(info);
    *priv = NULL;
    return 0;
}

ERL_NIF_TERM hash_murmur3_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);

    ErlNifBinary key;
    uint32_t seed;

    if (!get_binary(env, argv[0], &key))
        return make_badarg(env);

    if (!enif_get_uint(env, argv[1], &seed))
        return make_badarg(env);

    return enif_make_int(env, hash_murmur3_x64_128(key.data, key.size, seed));
}

ERL_NIF_TERM hash_murmur2_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);

    ErlNifBinary key;

    if (!get_binary(env, argv[0], &key))
        return make_badarg(env);

    return enif_make_uint(env, hash_murmur2(key.data, key.size));
}

ERL_NIF_TERM hash_fnv1_64_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);

    ErlNifBinary key;

    if (!get_binary(env, argv[0], &key))
        return make_badarg(env);

    return enif_make_uint(env, hash_fnv1_64(key.data, key.size));
}

ERL_NIF_TERM hash_fnv1a_64_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);

    ErlNifBinary key;

    if (!get_binary(env, argv[0], &key))
        return make_badarg(env);

    return enif_make_uint(env, hash_fnv1a_64(key.data, key.size));
}

ERL_NIF_TERM hash_fnv1_32_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);

    ErlNifBinary key;

    if (!get_binary(env, argv[0], &key))
        return make_badarg(env);

    return enif_make_uint(env, hash_fnv1_32(key.data, key.size));
}

ERL_NIF_TERM hash_fnv1a_32_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    UNUSED(argc);

    ErlNifBinary key;

    if (!get_binary(env, argv[0], &key))
        return make_badarg(env);

    return enif_make_uint(env, hash_fnv1a_32(key.data, key.size));
}

static ErlNifFunc nif_funcs[] =
{
    {"murmur3_x64_128", 2, hash_murmur3_nif},
    {"murmur2", 1, hash_murmur2_nif},
    {"fnv1_64", 1, hash_fnv1_64_nif},
    {"fnv1a_64", 1, hash_fnv1a_64_nif},
    {"fnv1_32", 1, hash_fnv1_32_nif},
    {"fnv1a_32", 1, hash_fnv1a_32_nif},
};

ERL_NIF_INIT(erl_hash_nif, nif_funcs, on_nif_load, NULL, on_nif_upgrade, on_nif_unload)
