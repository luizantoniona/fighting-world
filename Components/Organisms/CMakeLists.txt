set( SOURCES
    LoginScreen/LoginScreen.cpp
    Screen.cpp
)

set( HEADERS
    LoginScreen/LoginScreen.h
    Screen.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})