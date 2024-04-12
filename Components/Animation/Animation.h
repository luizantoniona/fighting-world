#pragma once

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Animation/AnimationActionType.h>
#include <Components/Animation/AnimationData.h>
#include <Components/Animation/AnimationDirectionType.h>
#include <Components/Animation/AnimationMovementType.h>

BEGIN_NAMESPACE_COMPONENT

class Animation {
public:
    Animation(const Component::AnimationData& animation, sf::Sprite& sprite);
    ~Animation();

    void update(sf::Time time,
        Component::AnimationActionType animationAction,
        Component::AnimationMovementType animationMovement,
        Component::AnimationDirectionType animationDirection);

private:
    void updateDirection(Component::AnimationDirectionType actionDirection);

    int _index;
    sf::Time _elapsed;
    sf::Time _animationTime;
    sf::Sprite& _sprite;

    const Component::AnimationData& _animation;
};

END_NAMESPACE_COMPONENT