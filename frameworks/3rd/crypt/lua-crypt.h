#ifndef __LCRYPT_H__
#define __LCRYPT_H__

#if __cplusplus
extern "C" {
#endif

#include "lua.h"

LUALIB_API int luaopen_crypt(lua_State *L);

#if __cplusplus
}
#endif

#endif