set(SOURCES
    Resource/ResourceManager.cpp
    Window/WindowManager.cpp
)

set(HEADERS
    Manager_Globals.h
    Resource/ResourceManager.h
    Window/WindowManager.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})