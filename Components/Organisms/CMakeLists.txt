set( SOURCES
    Screen.cpp
)

set( HEADERS
    Screen.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})