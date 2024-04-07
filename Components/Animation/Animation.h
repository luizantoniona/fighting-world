#pragma once

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationComposition.h>
#include <Components/Animation/AnimationDirectionType.h>
#include <Components/Animation/AnimationMovementType.h>
#include <Components/Animation/AnimationType.h>

BEGIN_NAMESPACE_COMPONENT

class Animation {
public:
    Animation(const Component::AnimationComposition& animation, sf::Sprite& sprite);
    ~Animation();

    void update(sf::Time time, Component::AnimationType action,
        Component::AnimationMovementType actionMovement,
        Component::AnimationDirectionType animationDirection);

private:
    void updateDirection(Component::AnimationDirectionType actionDirection);

    const Component::AnimationComposition& _animation;
    sf::Time _elapsed = {};
    sf::Time _animationTime;
    int _index;
    sf::Sprite& _sprite;
};

END_NAMESPACE_COMPONENT