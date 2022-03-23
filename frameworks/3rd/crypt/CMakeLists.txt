cmake_minimum_required(VERSION 3.6)

set(CRYPT_HEADER
    lua-crypt.h
)
set(CRYPT_SRC
    lua-crypt.c
    lsha1.c
)

list(APPEND CRYPT_SRC ${CRYPT_HEADER})

add_library(crypt ${CRYPT_SRC})

target_link_libraries(crypt 
	PRIVATE xgame
	PRIVATE cocos2d
)

if(APPLE)
    target_compile_options(crypt PRIVATE -Wno-shorten-64-to-32)
    target_compile_options(crypt PRIVATE -Wno-unreachable-code)
    target_compile_options(crypt PRIVATE -Wno-comma)
    target_compile_options(crypt PRIVATE "-Wno-#warnings")
endif()

target_include_directories(crypt
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(crypt PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua/3rd"
)

if(XCODE OR VS)
    cocos_mark_code_files("crypt" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()