#pragma once

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationMovementType.h>
#include <Components/Animation/AnimationType.h>

BEGIN_NAMESPACE_COMPONENT

using AnimationPair = std::pair<Component::AnimationMovementType, Component::AnimationType>;

struct AnimationComposition {
    using AnimationType = std::map<AnimationPair, std::vector<sf::IntRect>>;

    AnimationType _animationData;
};

END_NAMESPACE_COMPONENT
