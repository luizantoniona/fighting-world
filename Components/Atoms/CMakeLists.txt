set( SOURCES
    Animation/Animation.cpp
)

set( HEADERS
    Animation/Animation.h
    Animation/AnimationDirectionEnum.h
    Animation/AnimationEnum.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})