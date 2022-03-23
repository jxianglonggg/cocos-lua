cmake_minimum_required(VERSION 3.6)

set(YASIO_HEADER
    compiler/feature_test.hpp
    cxx17/memory.hpp
    cxx17/shared_mutex.hpp
    cxx17/string_view.hpp
    
    detail/ares.hpp
    detail/byte_buffer.hpp
    detail/concurrent_queue.hpp
    detail/config.hpp
    detail/endian_portable.hpp
    detail/eventfd_select_interrupter.hpp
    detail/fp16.hpp
    detail/ibstream.hpp
    detail/ifaddrs.hpp
    detail/logging.hpp
    detail/object_pool.hpp
    detail/obstream.hpp
    detail/pipe_select_interrupter.hpp
    detail/ref_ptr.hpp
    detail/select_interrupter.hpp
    detail/singleton.hpp
    detail/socket.hpp
    detail/socket_select_interrupter.hpp
    detail/ssl.hpp
    detail/strfmt.hpp
    detail/sz.hpp
    detail/thread_name.hpp
    detail/utils.hpp

    ibstream.hpp
    lua_yasio.h
    obstream.hpp
    xxsocket.hpp
    yasio.hpp
    yasio_fwd.hpp
)

set(YASIO_SRC
    xxsocket.cpp
    yasio.cpp
    lua_yasio.cpp
)

list(APPEND YASIO_SRC ${YASIO_HEADER})

add_library(yasio ${YASIO_SRC})

target_link_libraries(yasio 
	PRIVATE xgame
	PRIVATE cocos2d
)

if(APPLE)
    target_compile_options(yasio PRIVATE -Wno-strict-prototypes)
endif()

target_include_directories(yasio
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(yasio PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua/3rd"
)

if(XCODE OR VS)
    cocos_mark_code_files("yasio" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()