-module(erl_hash_nif).

-define(NOT_LOADED, not_loaded(?LINE)).

-on_load(load_nif/0).

-export([
    murmur3_x64_128/2,
    murmur2/1,
    fnv1_32/1,
    fnv1a_32/1,
    fnv1_64/1,
    fnv1a_64/1
]).

%% nif functions

load_nif() ->
    SoName = get_priv_path(?MODULE),
    io:format(<<"Loading library: ~p ~n">>, [SoName]),
    ok = erlang:load_nif(SoName, 0).

get_priv_path(File) ->
    case code:priv_dir(erl_hash) of
        {error, bad_name} ->
            Ebin = filename:dirname(code:which(?MODULE)),
            filename:join([filename:dirname(Ebin), "priv", File]);
        Dir ->
            filename:join(Dir, File)
    end.

not_loaded(Line) ->
    erlang:nif_error({not_loaded, [{module, ?MODULE}, {line, Line}]}).

murmur3_x64_128(_Key, _Seed) ->
    ?NOT_LOADED.

murmur2(_Key) ->
    ?NOT_LOADED.

fnv1_32(_Key) ->
    ?NOT_LOADED.

fnv1a_32(_Key) ->
    ?NOT_LOADED.

fnv1_64(_Key) ->
    ?NOT_LOADED.

fnv1a_64(_Key) ->
    ?NOT_LOADED.
