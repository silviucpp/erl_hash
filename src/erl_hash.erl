-module(erl_hash).

-export([
    murmur3_x64_128/2,
    murmur2/1,
    fnv1_32/1,
    fnv1a_32/1,
    fnv1_64/1,
    fnv1a_64/1
]).

-spec murmur3_x64_128(binary(), non_neg_integer()) ->
    integer().

murmur3_x64_128(Key, Seed) ->
    erl_hash_nif:murmur3_x64_128(Key, Seed).

-spec murmur2(binary()) ->
    non_neg_integer().

murmur2(Key) ->
    erl_hash_nif:murmur2(Key).

-spec fnv1_32(binary()) ->
    non_neg_integer().

fnv1_32(Key) ->
    erl_hash_nif:fnv1_32(Key).

-spec fnv1a_32(binary()) ->
    non_neg_integer().

fnv1a_32(Key) ->
    erl_hash_nif:fnv1a_32(Key).

-spec fnv1_64(binary()) ->
    non_neg_integer().

fnv1_64(Key) ->
    erl_hash_nif:fnv1_64(Key).

-spec fnv1a_64(binary()) ->
    non_neg_integer().

fnv1a_64(Key) ->
    erl_hash_nif:fnv1a_64(Key).
