set( SOURCES
)

set( HEADERS
    Components_Globals.h
)

add_subdirectory(Animation)
add_subdirectory(Button)
add_subdirectory(Entity)
add_subdirectory(Font)
add_subdirectory(Screen)
add_subdirectory(Window)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})