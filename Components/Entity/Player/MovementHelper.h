#pragma once

#include <string>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationDirectionType.h>

BEGIN_NAMESPACE_COMPONENT

class MovementHelper {
public:
    static Component::AnimationDirectionType movementDirectionByKey(const bool isW, const bool isA, const bool isS, const bool isD);
};

END_NAMESPACE_COMPONENT
