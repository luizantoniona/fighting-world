set( SOURCES
    Button.cpp
)

set( HEADERS
    Button.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})