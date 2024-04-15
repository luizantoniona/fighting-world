set( SOURCES
    FontHelper.cpp
)

set( HEADERS
    FontEnum.h
    FontHelper.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})