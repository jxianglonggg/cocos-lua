//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_yasio.h"

// yasio transport_handle_t
static inline bool olua_is_yasio_transport_handle_t(lua_State *L, int idx)
{
    return olua_isa<yasio::io_transport>(L, idx);
}

static inline int olua_push_yasio_transport_handle_t(lua_State* L, yasio::transport_handle_t* ptr)
{
    yasio::io_transport* it = (*ptr);
    olua_push_cppobj(L, it, "yasio.io_transport");
    return 1;
}

// yasio packet_t
static inline int olua_push_yasio_packet_t(lua_State *L,  yasio::packet_t *ptr)
{
    yasio::packet_t &packet = *ptr;
    lua_pushlstring(L, packet.begin(), packet.size());
    return 1;
}

static inline void olua_check_yasio_transport_handle_t(lua_State *L, int idx, yasio::io_transport **value)
{
    olua_check_obj(L, 3, (void **)&value, "yasio::io_transport *");
    *value = olua_checkobj<yasio::io_transport>(L, 3);
}

// yasio event_ptr
static inline int olua_push_yasio_event_ptr(lua_State *L, yasio::event_ptr *ptr)
{
    yasio::io_event* ev = (*ptr).get();
    olua_push_cppobj(L, ev, "yasio.io_event");
    return 1;
}

// yasio sbyte_buffer
static inline bool olua_is_yasio_sbyte_buffer(lua_State *L, int idx)
{
    return olua_isstring(L, idx);
}

static inline int olua_push_yasio_sbyte_buffer(lua_State *L, const yasio::sbyte_buffer &value)
{
    lua_pushlstring(L, value.begin(), value.size());
    return 1;
}

static inline void olua_check_yasio_sbyte_buffer(lua_State *L, int idx, yasio::sbyte_buffer *value)
{
    size_t len;
    const char *str = olua_checklstring(L, idx, &len);
    std::string s = str;
    *value =  yasio::sbyte_buffer(s.begin(), s.end());
}

static int olua_push_yasio_highp_timer_ptr(lua_State *L, yasio::highp_timer_ptr *obj)
{
    olua_push_cppobj(L, obj->get());
    return 1;
}

int olua_push_yasio_io_hostent(lua_State *L, const yasio::io_hostent *value)
{
    if (value) {
        lua_createtable(L, 0, 2);

        olua_push_std_string(L, value->host_);
        olua_setfield(L, -2, "host_");

        olua_push_uint(L, (lua_Unsigned)value->port_);
        olua_setfield(L, -2, "port_");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void olua_check_yasio_io_hostent(lua_State *L, int idx, yasio::io_hostent *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** host_ */
    lua_Unsigned arg2 = 0;       /** port_ */

    olua_getfield(L, idx, "host_");
    olua_check_std_string(L, -1, &arg1);
    value->host_ = (std::string)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "port_");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg2);
        value->port_ = (u_short)arg2;
    }
    lua_pop(L, 1);
}

bool olua_is_yasio_io_hostent(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "host_");
}

void olua_pack_yasio_io_hostent(lua_State *L, int idx, yasio::io_hostent *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** host_ */
    lua_Unsigned arg2 = 0;       /** port_ */

    olua_check_std_string(L, idx + 0, &arg1);
    value->host_ = (std::string)arg1;

    olua_check_uint(L, idx + 1, &arg2);
    value->port_ = (u_short)arg2;
}

int olua_unpack_yasio_io_hostent(lua_State *L, const yasio::io_hostent *value)
{
    if (value) {
        olua_push_std_string(L, value->host_);
        olua_push_uint(L, (lua_Unsigned)value->port_);
    } else {
        for (int i = 0; i < 2; i++) {
            lua_pushnil(L);
        }
    }

    return 2;
}

bool olua_canpack_yasio_io_hostent(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_uint(L, idx + 1);
}

static int _yasio_io_event___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (yasio::io_event *)olua_toobj(L, 1, "yasio.io_event");
    olua_push_cppobj(L, self, "yasio.io_event");

    olua_endinvoke(L);

    return 1;
}

static int _yasio_io_event_cindex(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // int cindex()
    int ret = self->cindex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_kind(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // int kind()
    int ret = self->kind();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_packet(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // yasio::packet_t &packet()
    yasio::packet_t &ret = self->packet();
    int num_ret = olua_push_yasio_packet_t(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_passive(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // int passive()
    int ret = self->passive();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_source(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // yasio::io_base *source()
    yasio::io_base *ret = self->source();
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_base");

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_source_id(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // unsigned int source_id()
    unsigned int ret = self->source_id();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_status(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // int status()
    int ret = self->status();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_timestamp(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // yasio::highp_time_t timestamp()
    yasio::highp_time_t ret = self->timestamp();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_event_transport(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_event");

    // yasio::transport_handle_t transport()
    yasio::transport_handle_t ret = self->transport();
    int num_ret = olua_push_yasio_transport_handle_t(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio_io_event(lua_State *L)
{
    oluacls_class(L, "yasio.io_event", nullptr);
    oluacls_func(L, "__olua_move", _yasio_io_event___olua_move);
    oluacls_func(L, "cindex", _yasio_io_event_cindex);
    oluacls_func(L, "kind", _yasio_io_event_kind);
    oluacls_func(L, "packet", _yasio_io_event_packet);
    oluacls_func(L, "passive", _yasio_io_event_passive);
    oluacls_func(L, "source", _yasio_io_event_source);
    oluacls_func(L, "source_id", _yasio_io_event_source_id);
    oluacls_func(L, "status", _yasio_io_event_status);
    oluacls_func(L, "timestamp", _yasio_io_event_timestamp);
    oluacls_func(L, "transport", _yasio_io_event_transport);

    olua_registerluatype<yasio::io_event>(L, "yasio.io_event");

    return 1;
}
OLUA_END_DECLS

static int _addrinfo___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (addrinfo *)olua_toobj(L, 1, "addrinfo");
    olua_push_cppobj(L, self, "addrinfo");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_addrinfo(lua_State *L)
{
    oluacls_class(L, "addrinfo", nullptr);
    oluacls_func(L, "__olua_move", _addrinfo___olua_move);

    olua_registerluatype<addrinfo>(L, "addrinfo");

    return 1;
}
OLUA_END_DECLS

static int _sockaddr___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (sockaddr *)olua_toobj(L, 1, "sockaddr");
    olua_push_cppobj(L, self, "sockaddr");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_sockaddr(lua_State *L)
{
    oluacls_class(L, "sockaddr", nullptr);
    oluacls_func(L, "__olua_move", _sockaddr___olua_move);

    olua_registerluatype<sockaddr>(L, "sockaddr");

    return 1;
}
OLUA_END_DECLS

static int _yasio_io_base___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (yasio::io_base *)olua_toobj(L, 1, "yasio.io_base");
    olua_push_cppobj(L, self, "yasio.io_base");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio_io_base(lua_State *L)
{
    oluacls_class(L, "yasio.io_base", nullptr);
    oluacls_func(L, "__olua_move", _yasio_io_base___olua_move);

    olua_registerluatype<yasio::io_base>(L, "yasio.io_base");

    return 1;
}
OLUA_END_DECLS

static int _yasio_io_transport___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (yasio::io_transport *)olua_toobj(L, 1, "yasio.io_transport");
    olua_push_cppobj(L, self, "yasio.io_transport");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio_io_transport(lua_State *L)
{
    oluacls_class(L, "yasio.io_transport", "yasio.io_base");
    oluacls_func(L, "__olua_move", _yasio_io_transport___olua_move);

    olua_registerluatype<yasio::io_transport>(L, "yasio.io_transport");

    return 1;
}
OLUA_END_DECLS

static int _yasio_io_service___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<yasio::io_service>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (yasio::io_service *)olua_toobj(L, 1, "yasio.io_service");
    olua_push_cppobj(L, self, "yasio.io_service");

    olua_endinvoke(L);

    return 1;
}

static int _yasio_io_service_channel_at(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_uint(L, 2, &arg1);

    // yasio::io_channel *channel_at(size_t index)
    yasio::io_channel *ret = self->channel_at((size_t)arg1);
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_channel");

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_cleanup_globals(lua_State *L)
{
    olua_startinvoke(L);

    // static void cleanup_globals()
    yasio::io_service::cleanup_globals();

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service_dispatch1(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    lua_Integer arg1 = 0;       /** max_count */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_int(L, 2, &arg1);

    // void dispatch(@optional int max_count)
    self->dispatch((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service_dispatch2(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");

    // void dispatch(@optional int max_count)
    self->dispatch();

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service_dispatch(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void dispatch(@optional int max_count)
        return _yasio_io_service_dispatch2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void dispatch(@optional int max_count)
            return _yasio_io_service_dispatch1(L);
        // }
    }

    luaL_error(L, "method 'yasio::io_service::dispatch' not support '%d' arguments", num_args);

    return 0;
}

static int _yasio_io_service_is_running(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");

    // bool is_running()
    bool ret = self->is_running();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_is_stopping(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");

    // bool is_stopping()
    bool ret = self->is_stopping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_new1(lua_State *L)
{
    olua_startinvoke(L);

    // io_service()
    yasio::io_service *ret = new yasio::io_service();
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_service");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_new2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** channel_count */

    olua_check_int(L, 1, &arg1);

    // io_service(int channel_count)
    yasio::io_service *ret = new yasio::io_service((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_service");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_new3(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_hostent arg1;       /** channel_eps */

    olua_check_yasio_io_hostent(L, 1, &arg1);

    // io_service(const yasio::io_hostent &channel_eps)
    yasio::io_service *ret = new yasio::io_service(arg1);
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_service");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_new4(lua_State *L)
{
    olua_startinvoke(L);

    std::vector<yasio::io_hostent> arg1;       /** channel_eps */

    olua_check_array<yasio::io_hostent>(L, 1, &arg1, [L](yasio::io_hostent *value) {
        olua_check_yasio_io_hostent(L, -1, value);
    });

    // io_service(const std::vector<io_hostent> &channel_eps)
    yasio::io_service *ret = new yasio::io_service(arg1);
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_service");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_new5(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_hostent arg1;       /** channel_eps */
    lua_Integer arg2 = 0;       /** channel_count */

    olua_check_yasio_io_hostent(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // io_service(const yasio::io_hostent *channel_eps, int channel_count)
    yasio::io_service *ret = new yasio::io_service(&arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "yasio.io_service");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // io_service()
        return _yasio_io_service_new1(L);
    }

    if (num_args == 1) {
        if ((olua_is_yasio_io_hostent(L, 1))) {
            // io_service(const yasio::io_hostent &channel_eps)
            return _yasio_io_service_new3(L);
        }

        if ((olua_is_int(L, 1))) {
            // io_service(int channel_count)
            return _yasio_io_service_new2(L);
        }

        // if ((olua_is_array(L, 1))) {
            // io_service(const std::vector<io_hostent> &channel_eps)
            return _yasio_io_service_new4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_yasio_io_hostent(L, 1)) && (olua_is_int(L, 2))) {
            // io_service(const yasio::io_hostent *channel_eps, int channel_count)
            return _yasio_io_service_new5(L);
        // }
    }

    luaL_error(L, "method 'yasio::io_service::new' not support '%d' arguments", num_args);

    return 0;
}

static int _yasio_io_service_open1(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */
    lua_Integer arg2 = 0;       /** kind */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // bool open(size_t index, @optional int kind)
    bool ret = self->open((size_t)arg1, (int)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_open2(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_uint(L, 2, &arg1);

    // bool open(size_t index, @optional int kind)
    bool ret = self->open((size_t)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_open(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // bool open(size_t index, @optional int kind)
            return _yasio_io_service_open2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_int(L, 3))) {
            // bool open(size_t index, @optional int kind)
            return _yasio_io_service_open1(L);
        // }
    }

    luaL_error(L, "method 'yasio::io_service::open' not support '%d' arguments", num_args);

    return 0;
}

static int _yasio_io_service_schedule(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    lua_Integer arg1 = 0;       /** duration */
    std::function<bool(yasio::io_service &)> arg2;       /**  */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_int(L, 2, &arg1);
    olua_check_callback(L, 3, &arg2, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "schedule";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](yasio::io_service &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();
        bool ret = false;       
        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, &arg1, "yasio.io_service");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return (bool)ret;
    };

    // yasio::highp_timer_ptr schedule(const std::chrono::microseconds &duration, @localvar std::function<bool (yasio::io_service &)> )
    yasio::highp_timer_ptr ret = self->schedule((std::chrono::microseconds)arg1, arg2);
    int num_ret = olua_push_yasio_highp_timer_ptr(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_set_unpack_frame_option(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    lua_Integer arg1 = 0;       /** index:int */
    lua_Integer arg2 = 0;       /** max_frame_length:int */
    lua_Integer arg3 = 0;       /** length_field_offset:int */
    lua_Integer arg4 = 0;       /** length_field_length:int */
    lua_Integer arg5 = 0;       /** length_adjustment:int */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);
    olua_check_int(L, 6, &arg5);

    int index = static_cast<int>(arg1);
    int max_frame_length = static_cast<int>(arg2);
    int length_field_offset = static_cast<int>(arg3);
    int length_field_length = static_cast<int>(arg4);
    int length_adjustment = static_cast<int>(arg5);

    self->set_option(yasio::YOPT_C_UNPACK_PARAMS, index, max_frame_length, length_field_offset, length_field_length, length_adjustment);

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service_start(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    std::function<void(yasio::event_ptr &&)> arg1;       /** cb */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_callback(L, 2, &arg1, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "start";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](yasio::event_ptr &&arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_yasio_event_ptr(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void start(@localvar std::function<void (yasio::event_ptr &&)> cb)
    self->start(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service_stop(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _yasio_io_service_write1(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    yasio::io_transport *arg1;       /** thandle */
    void *arg2 = nullptr;       /** buf */
    lua_Unsigned arg3 = 0;       /** len */
    std::function<void(int, size_t)> arg4;       /** completion_handler */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_yasio_transport_handle_t(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    olua_check_uint(L, 4, &arg3);
    olua_check_callback(L, 5, &arg4, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "write";
    std::string cb_name;
    if (olua_is_callback(L, 5, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  5, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg4 = [cb_store, cb_name, cb_ctx](int arg1, size_t arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                olua_push_int(L, (lua_Integer)arg1);
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg4 = nullptr;
    }

    // int write(yasio::transport_handle_t thandle, const void *buf, size_t len, @localvar @optional std::function<void (int, size_t)> completion_handler)
    int ret = self->write((yasio::transport_handle_t)arg1, arg2, (size_t)arg3, arg4);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_write2(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    yasio::io_transport *arg1;       /** thandle */
    yasio::sbyte_buffer arg2;       /** buffer */
    std::function<void(int, size_t)> arg3;       /** completion_handler */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_yasio_transport_handle_t(L, 2, &arg1);
    olua_check_yasio_sbyte_buffer(L, 3, &arg2);
    olua_check_callback(L, 4, &arg3, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "write";
    std::string cb_name;
    if (olua_is_callback(L, 4, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  4, cb_tag.c_str(), OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg3 = [cb_store, cb_name, cb_ctx](int arg1, size_t arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                olua_push_int(L, (lua_Integer)arg1);
                olua_push_uint(L, (lua_Unsigned)arg2);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg3 = nullptr;
    }

    // int write(yasio::transport_handle_t thandle, yasio::sbyte_buffer buffer, @localvar @optional std::function<void (int, size_t)> completion_handler)
    int ret = self->write((yasio::transport_handle_t)arg1, arg2, arg3);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_write3(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    yasio::io_transport *arg1;       /** thandle */
    void *arg2 = nullptr;       /** buf */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_yasio_transport_handle_t(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    olua_check_uint(L, 4, &arg3);

    // int write(yasio::transport_handle_t thandle, const void *buf, size_t len, @localvar @optional std::function<void (int, size_t)> completion_handler)
    int ret = self->write((yasio::transport_handle_t)arg1, arg2, (size_t)arg3);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_write4(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_service *self = nullptr;
    yasio::io_transport *arg1;       /** thandle */
    yasio::sbyte_buffer arg2;       /** buffer */

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_service");
    olua_check_yasio_transport_handle_t(L, 2, &arg1);
    olua_check_yasio_sbyte_buffer(L, 3, &arg2);

    // int write(yasio::transport_handle_t thandle, yasio::sbyte_buffer buffer, @localvar @optional std::function<void (int, size_t)> completion_handler)
    int ret = self->write((yasio::transport_handle_t)arg1, arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_service_write(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_yasio_transport_handle_t(L, 2)) && (olua_is_yasio_sbyte_buffer(L, 3))) {
            // int write(yasio::transport_handle_t thandle, yasio::sbyte_buffer buffer, @localvar @optional std::function<void (int, size_t)> completion_handler)
            return _yasio_io_service_write4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_yasio_transport_handle_t(L, 2)) && (olua_is_yasio_sbyte_buffer(L, 3)) && (olua_is_callback(L, 4, "std.function"))) {
            // int write(yasio::transport_handle_t thandle, yasio::sbyte_buffer buffer, @localvar @optional std::function<void (int, size_t)> completion_handler)
            return _yasio_io_service_write2(L);
        }

        // if ((olua_is_yasio_transport_handle_t(L, 2)) && (olua_is_obj(L, 3, "void *")) && (olua_is_uint(L, 4))) {
            // int write(yasio::transport_handle_t thandle, const void *buf, size_t len, @localvar @optional std::function<void (int, size_t)> completion_handler)
            return _yasio_io_service_write3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_yasio_transport_handle_t(L, 2)) && (olua_is_obj(L, 3, "void *")) && (olua_is_uint(L, 4)) && (olua_is_callback(L, 5, "std.function"))) {
            // int write(yasio::transport_handle_t thandle, const void *buf, size_t len, @localvar @optional std::function<void (int, size_t)> completion_handler)
            return _yasio_io_service_write1(L);
        // }
    }

    luaL_error(L, "method 'yasio::io_service::write' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio_io_service(lua_State *L)
{
    oluacls_class(L, "yasio.io_service", nullptr);
    oluacls_func(L, "__gc", _yasio_io_service___gc);
    oluacls_func(L, "__olua_move", _yasio_io_service___olua_move);
    oluacls_func(L, "channel_at", _yasio_io_service_channel_at);
    oluacls_func(L, "cleanup_globals", _yasio_io_service_cleanup_globals);
    oluacls_func(L, "dispatch", _yasio_io_service_dispatch);
    oluacls_func(L, "is_running", _yasio_io_service_is_running);
    oluacls_func(L, "is_stopping", _yasio_io_service_is_stopping);
    oluacls_func(L, "new", _yasio_io_service_new);
    oluacls_func(L, "open", _yasio_io_service_open);
    oluacls_func(L, "schedule", _yasio_io_service_schedule);
    oluacls_func(L, "set_unpack_frame_option", _yasio_io_service_set_unpack_frame_option);
    oluacls_func(L, "start", _yasio_io_service_start);
    oluacls_func(L, "stop", _yasio_io_service_stop);
    oluacls_func(L, "write", _yasio_io_service_write);
    oluacls_prop(L, "_running", _yasio_io_service_is_running, nullptr);
    oluacls_prop(L, "_stopping", _yasio_io_service_is_stopping, nullptr);

    olua_registerluatype<yasio::io_service>(L, "yasio.io_service");

    return 1;
}
OLUA_END_DECLS

static int _yasio_io_channel___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (yasio::io_channel *)olua_toobj(L, 1, "yasio.io_channel");
    olua_push_cppobj(L, self, "yasio.io_channel");

    olua_endinvoke(L);

    return 1;
}

static int _yasio_io_channel_bytes_transferred(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_channel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_channel");

    // long long bytes_transferred()
    long long ret = self->bytes_transferred();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_channel_connect_id(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_channel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_channel");

    // unsigned int connect_id()
    unsigned int ret = self->connect_id();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_channel_format_destination(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_channel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_channel");

    // std::string format_destination()
    std::string ret = self->format_destination();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_channel_get_service(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_channel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_channel");

    // yasio::io_service &get_service()
    yasio::io_service &ret = self->get_service();
    int num_ret = olua_push_cppobj(L, &ret, "yasio.io_service");

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_channel_index(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_channel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_channel");

    // int index()
    int ret = self->index();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _yasio_io_channel_remote_port(lua_State *L)
{
    olua_startinvoke(L);

    yasio::io_channel *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "yasio.io_channel");

    // u_short remote_port()
    u_short ret = self->remote_port();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio_io_channel(lua_State *L)
{
    oluacls_class(L, "yasio.io_channel", "yasio.io_base");
    oluacls_func(L, "__olua_move", _yasio_io_channel___olua_move);
    oluacls_func(L, "bytes_transferred", _yasio_io_channel_bytes_transferred);
    oluacls_func(L, "connect_id", _yasio_io_channel_connect_id);
    oluacls_func(L, "format_destination", _yasio_io_channel_format_destination);
    oluacls_func(L, "get_service", _yasio_io_channel_get_service);
    oluacls_func(L, "index", _yasio_io_channel_index);
    oluacls_func(L, "remote_port", _yasio_io_channel_remote_port);
    oluacls_prop(L, "_service", _yasio_io_channel_get_service, nullptr);

    olua_registerluatype<yasio::io_channel>(L, "yasio.io_channel");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_yasio(lua_State *L)
{
    olua_require(L, "yasio.io_event", luaopen_yasio_io_event);
    olua_require(L, "addrinfo", luaopen_addrinfo);
    olua_require(L, "sockaddr", luaopen_sockaddr);
    olua_require(L, "yasio.io_base", luaopen_yasio_io_base);
    olua_require(L, "yasio.io_transport", luaopen_yasio_io_transport);
    olua_require(L, "yasio.io_service", luaopen_yasio_io_service);
    olua_require(L, "yasio.io_channel", luaopen_yasio_io_channel);

    return 0;
}
OLUA_END_DECLS
