# List of source files
set( SOURCES
)

# List of header files
set( HEADERS
    Components_Globals.h
)

# Add sources to the executable target
target_sources( MFW PUBLIC ${SOURCES})

# Add headers to the target's include directories
target_include_directories( MFW PUBLIC ${HEADERS})