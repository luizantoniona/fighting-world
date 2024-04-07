set( SOURCES
    Animation.cpp
)

set( HEADERS
    Animation.h
    AnimationComposition.h
    AnimationDirectionType.h
    AnimationMovementType.h
    AnimationType.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})