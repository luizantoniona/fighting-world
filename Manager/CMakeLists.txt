set(SOURCES
    Resource/ResourceManager.cpp
)

set(HEADERS
    Manager_Globals.h
    Resource/ResourceManager.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})