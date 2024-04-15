set( SOURCES
    Arena/Arena.cpp
    Loading/Loading.cpp
    Menu/Menu.cpp
    Screen.cpp
)

set( HEADERS
    Arena/Arena.h
    Loading/Loading.h
    Menu/Menu.h
    Screen.h
    ScreenEnum.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})