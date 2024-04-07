#include "Animation.h"

#include <iostream>

BEGIN_NAMESPACE_COMPONENT

Animation::Animation(const Component::AnimationComposition& animation, sf::Sprite& sprite)
    : _animation(animation)
    , _sprite(sprite)
    , _animationTime(sf::seconds(0.1))
    , _index(0)
{
}

Animation::~Animation() { }

void Animation::update(sf::Time time, Component::AnimationType action,
    Component::AnimationMovementType actionMovement,
    Component::AnimationDirectionType animationDirection)
{
    _elapsed += time;

    if (_elapsed >= _animationTime) {
        _elapsed -= _animationTime;
        _index++;

        Component::AnimationPair key = std::make_pair(actionMovement, action);

        if (_index >= _animation._animationData.at(key).size()) {
            _index = 0;
        }

        _sprite.setTextureRect(_animation._animationData.at(key)[_index]);

        updateDirection(animationDirection);
    }
}

void Animation::updateDirection(Component::AnimationDirectionType actionDirection)
{
    const bool isFancingLeft = actionDirection == Component::AnimationDirectionType::LEFT
        || actionDirection == Component::AnimationDirectionType::LEFT_DOWN
        || actionDirection == Component::AnimationDirectionType::LEFT_UP;

    const bool isFacingRight = actionDirection == Component::AnimationDirectionType::RIGHT
        || actionDirection == Component::AnimationDirectionType::RIGHT_DOWN
        || actionDirection == Component::AnimationDirectionType::RIGHT_UP;

    if ((isFancingLeft && _sprite.getScale().x > 0) || (isFacingRight && _sprite.getScale().x < 0)) {
        _sprite.scale(-1, 1);
    }
}

END_NAMESPACE_COMPONENT