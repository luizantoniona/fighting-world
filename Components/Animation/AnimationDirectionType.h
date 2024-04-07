#pragma once

#include <SFML/graphics.hpp>

#include <Components/Components_Globals.h>

BEGIN_NAMESPACE_COMPONENT

enum class AnimationDirectionType {
    STAY,
    RIGHT_UP,
    RIGHT,
    RIGHT_DOWN,
    LEFT_UP,
    LEFT,
    LEFT_DOWN,
    UP,
    DOWN,
};

END_NAMESPACE_COMPONENT

// STAY = { 0, 0 },
// RIGHT_UP = { 1, -1 },
// RIGHT = { 1, 0 },
// RIGHT_DOWN = { 1, 1 },
// LEFT_UP = { -1, -1 },
// LEFT = { -1, 0 },
// LEFT_DOWN = { -1, 1 },
// UP = { 0, -1 },
// DOWN = { 0, 1 },