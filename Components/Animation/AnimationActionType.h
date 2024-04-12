#pragma once

#include <Components/Components_Globals.h>

BEGIN_NAMESPACE_COMPONENT

enum class AnimationActionType : char {
    STANDING,
    PUNCHING,
    PUNCHING_LIGHT,
    PICKING_LIGHT,
    PICKING_HEAVY,
    LEADING_HEAVY,
    THROW_HEAVY,
    THROW_LIGHT,
    WEAPON_DRINK,
    DEFENDING,
    DEFENDING_BROKEN,
    INJURED,
    ICED,
    FIRED,
};

END_NAMESPACE_COMPONENT