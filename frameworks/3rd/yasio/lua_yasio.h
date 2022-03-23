//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_YASIO_H__
#define __AUTO_GEN_LUA_YASIO_H__

#include <vector>
#include "cclua/xlua.h"
#include "ibstream.hpp"
#include "obstream.hpp"
#include "yasio.hpp"
#include "xxsocket.hpp"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio(lua_State *L);
OLUA_END_DECLS

// yasio::io_hostent
int olua_push_yasio_io_hostent(lua_State *L, const yasio::io_hostent *value);
void olua_check_yasio_io_hostent(lua_State *L, int idx, yasio::io_hostent *value);
bool olua_is_yasio_io_hostent(lua_State *L, int idx);
void olua_pack_yasio_io_hostent(lua_State *L, int idx, yasio::io_hostent *value);
int olua_unpack_yasio_io_hostent(lua_State *L, const yasio::io_hostent *value);
bool olua_canpack_yasio_io_hostent(lua_State *L, int idx);

#endif