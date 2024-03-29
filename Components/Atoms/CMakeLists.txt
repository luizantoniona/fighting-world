set( SOURCES
    Button/Button.cpp
)

set( HEADERS
    Button/Button.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})