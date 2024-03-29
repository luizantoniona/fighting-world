set( SOURCES
    Window.cpp
)

set( HEADERS
    Window.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})