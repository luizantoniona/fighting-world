set( SOURCES
    Character/Character.cpp
    Character/CharacterHelper.cpp
    Enemy/Enemy.cpp
    Player/Player.cpp
    Player/MovementHelper.cpp
    Entity.cpp
)

set( HEADERS
    Character/Character.h
    Character/CharacterEnum.h
    Character/CharacterHelper.h
    Enemy/Enemy.h
    Player/Player.h
    Player/MovementHelper.h
    Entity.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})