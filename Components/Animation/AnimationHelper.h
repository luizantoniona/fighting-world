#pragma once

#include <string>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationData.h>

BEGIN_NAMESPACE_COMPONENT

class AnimationHelper {
public:
    static AnimationMovementAction animationTypeByString(const std::string& animationString);
};

END_NAMESPACE_COMPONENT