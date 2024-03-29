set(SOURCES
    Database.cpp
)

set(HEADERS
    Database_Globals.h
    Database.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})