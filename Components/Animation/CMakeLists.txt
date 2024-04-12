set( SOURCES
    Animation.cpp
    AnimationHelper.cpp
)

set( HEADERS
    Animation.h
    AnimationActionType.h
    AnimationData.h
    AnimationDirectionType.h
    AnimationHelper.h
    AnimationMovementType.h
)

target_sources( MFW PUBLIC ${SOURCES})

target_include_directories( MFW PUBLIC ${HEADERS})