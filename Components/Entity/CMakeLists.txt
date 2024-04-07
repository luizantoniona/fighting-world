set( SOURCES
    Character/Character.cpp
    Entity.cpp
)

set( HEADERS
    Character/Character.h
    Character/CharacterEnum.h
    Entity.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})