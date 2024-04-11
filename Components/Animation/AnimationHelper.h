#pragma once

#include <string>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationComposition.h>

BEGIN_NAMESPACE_COMPONENT

class AnimationHelper {
public:
    static AnimationPair animationTypeByString(const std::string& animationString);
};

END_NAMESPACE_COMPONENT