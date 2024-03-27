# List of source files
set(SOURCES
    Thread.cpp
)

# List of header files
set(HEADERS
    Thread.h
)

# Add sources to the executable target
target_sources( MFW PUBLIC ${SOURCES})

# Add headers to the target's include directories
target_include_directories( MFW PUBLIC ${HEADERS})