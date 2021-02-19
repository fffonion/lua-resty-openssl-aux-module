OPENRESTY_PREFIX=/usr/local/openresty

#LUA_VERSION := 5.1
PREFIX ?=          /usr/local
LUA_INCLUDE_DIR ?= $(PREFIX)/include
LUA_LIB_DIR ?=     $(PREFIX)/lib/lua/$(LUA_VERSION)
INSTALL ?= install

.PHONY: all test install

all: ;

install: all
	$(INSTALL) -d $(DESTDIR)$(LUA_LIB_DIR)/resty/openssl/auxiliary/
	$(INSTALL) -m 664 lualib/resty/openssl/auxiliary/*.lua $(DESTDIR)$(LUA_LIB_DIR)/resty/openssl/auxiliary/
