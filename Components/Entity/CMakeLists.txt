set( SOURCES
    Character/Character.cpp
    Character/CharacterHelper.cpp
    Entity.cpp
)

set( HEADERS
    Character/Character.h
    Character/CharacterEnum.h
    Character/CharacterHelper.h
    Entity.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})