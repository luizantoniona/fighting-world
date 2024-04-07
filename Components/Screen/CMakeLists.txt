set( SOURCES
    Arena/Arena.cpp
    Screen.cpp
)

set( HEADERS
    Arena/Arena.h
    Screen.h
    ScreenEnum.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})