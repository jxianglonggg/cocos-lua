set(CCLUA_HEADER
    src/cclua/AssetsBundle.h
    src/cclua/ByteArray.h
    src/cclua/downloader.h
    src/cclua/FileFinder.h
    src/cclua/filesystem-private.h
    src/cclua/filesystem.h
    src/cclua/luauser.h
    src/cclua/plugin.h
    src/cclua/preferences.h
    src/cclua/RootScene.h
    src/cclua/runtime-private.h
    src/cclua/runtime.h
    src/cclua/Socket.h
    src/cclua/timer.h
    src/cclua/window.h
    src/cclua/xlua.h
    src/cclua/XMLHttpRequest.h
)

set(CCLUA_SRC
    src/cclua/AssetsBundle.cpp
    src/cclua/ByteArray.cpp
    src/cclua/downloader.cpp
    src/cclua/FileFinder.cpp
    src/cclua/filesystem-private.cpp
    src/cclua/filesystem.cpp
    src/cclua/plugin.cpp
    src/cclua/preferences.cpp
    src/cclua/RootScene.cpp
    src/cclua/runtime-private.cpp
    src/cclua/runtime.cpp
    src/cclua/Socket.cpp
    src/cclua/timer.cpp
    src/cclua/window.cpp
    src/cclua/xlua.cpp
    src/cclua/XMLHttpRequest.cpp
)

if(APPLE)
    if(IOS)
        list(APPEND CCLUA_HEADER
            src/cclua/AppContext-ios.h
            src/cclua/AppRootViewController-ios.h
            src/cclua/plugin-ios.h
            src/cclua/PluginConnector.h
            src/cclua/Reachability.h
        )
        list(APPEND CCLUA_SRC
            src/cclua/AppContext-ios.mm
            src/cclua/AppRootViewController-ios.mm
            src/cclua/PluginConnector.mm
            src/cclua/Reachability.m
            src/cclua/filesystem-private-ios-mac.mm
            src/cclua/runtime-private-ios-mac.mm
        )
    elseif(MACOSX)
        list(APPEND CCLUA_SRC
            src/cclua/filesystem-private-ios-mac.mm
            src/cclua/runtime-private-ios-mac.mm
        )
    endif()
elseif(ANDROID)
    list(APPEND CCLUA_HEADER
        src/cclua/jniutil.h
    )
    list(APPEND CCLUA_SRC
        src/cclua/jniutil.cpp
    )
endif()
