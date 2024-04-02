set( SOURCES
)

set( HEADERS
    Components_Globals.h
)

add_subdirectory(Atoms)
add_subdirectory(Molecules)
add_subdirectory(Screen)
add_subdirectory(Window)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})