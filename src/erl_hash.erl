-module(erl_hash).

-export([
    murmur2/1,
    fnv1_32/1,
    fnv1a_32/1,
    fnv1_64/1,
    fnv1a_64/1
]).

murmur2(Key) ->
    erl_hash_nif:murmur2(Key).

fnv1_32(Key) ->
    erl_hash_nif:fnv1_32(Key).

fnv1a_32(Key) ->
    erl_hash_nif:fnv1a_32(Key).

fnv1_64(Key) ->
    erl_hash_nif:fnv1_64(Key).

fnv1a_64(Key) ->
    erl_hash_nif:fnv1a_64(Key).

