# List of source files
set( SOURCES
    Window.cpp
)

# List of header files
set( HEADERS
    Window.h
)

# Add sources to the executable target
target_sources( MFW PUBLIC ${SOURCES})

# Add headers to the target's include directories
target_include_directories( MFW PUBLIC ${HEADERS})