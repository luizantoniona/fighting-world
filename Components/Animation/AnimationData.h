#pragma once

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationActionType.h>
#include <Components/Animation/AnimationMovementType.h>

BEGIN_NAMESPACE_COMPONENT

using AnimationMovementAction = std::pair<Component::AnimationMovementType, Component::AnimationActionType>;
using AnimationTextureRectangle = std::vector<std::pair<int, sf::IntRect>>;
using AnimationType = std::map<AnimationMovementAction, AnimationTextureRectangle>;

struct AnimationData {
    std::vector<sf::Texture> _texture;
    AnimationType _animationData;
};

END_NAMESPACE_COMPONENT
