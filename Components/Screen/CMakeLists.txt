set( SOURCES
    LoadingScreen/LoadingScreen.cpp
    LoginScreen/LoginScreen.cpp
    MenuScreen/MenuScreen.cpp
    Screen.cpp
)

set( HEADERS
    LoadingScreen/LoadingScreen.h
    LoginScreen/LoginScreen.h
    MenuScreen/MenuScreen.h
    Screen.h
    ScreenEnum.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})