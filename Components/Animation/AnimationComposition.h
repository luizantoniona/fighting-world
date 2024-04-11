#pragma once

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationActionType.h>
#include <Components/Animation/AnimationMovementType.h>

BEGIN_NAMESPACE_COMPONENT

using AnimationPair = std::pair<Component::AnimationMovementType, Component::AnimationActionType>;

struct AnimationComposition {
    using AnimationType = std::map<AnimationPair, std::vector<sf::IntRect>>;

    AnimationType _animationData;
};

END_NAMESPACE_COMPONENT
