#pragma once

#include <Components/Components_Globals.h>

BEGIN_NAMESPACE_COMPONENT

enum class AnimationMovementType : char {
    STANDING,
    WALKING,
    RUNNING,
    RUNNING_STOP,
    JUMPING,
    FALLING,
    DASHING,
    ROWING,
    CROUCHING,
};

END_NAMESPACE_COMPONENT