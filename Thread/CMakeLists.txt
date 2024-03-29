set(SOURCES
    ThreadManager.cpp
    Thread.cpp
    Database/ThreadDatabase.cpp
)

set(HEADERS
    Thread_Globals.h
    ThreadManager.h
    Thread.h
    Database/ThreadDatabase.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})