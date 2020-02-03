
PROJECT_NIF_NAME=erl_hash_nif

include nif.mk

ifeq ($(UNAME_SYS), darwin)
	LDFLAGS +=  -Wl,-U,_enif_inspect_binary \
	            -Wl,-U,_enif_inspect_iolist_as_binary \
	            -Wl,-U,_enif_is_binary \
	            -Wl,-U,_enif_make_atom \
	            -Wl,-U,_enif_make_existing_atom \
	            -Wl,-U,_enif_make_tuple \
	            -Wl,-U,_enif_make_uint
endif

CXXFLAGS+=  -g -Wextra -Werror -Wno-missing-field-initializers -fno-rtti -fno-exceptions -Wno-implicit-fallthrough
LDFLAGS +=  -lstdc++