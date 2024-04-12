#include "Animation.h"

#include <iostream>

BEGIN_NAMESPACE_COMPONENT

Animation::Animation(const Component::AnimationData& animation, sf::Sprite& sprite)
    : _index(0)
    , _elapsed(sf::microseconds(0.0))
    , _animationTime(sf::seconds(0.1))
    , _sprite(sprite)
    , _animation(animation)
{
}

Animation::~Animation() { }

void Animation::update(sf::Time time,
    Component::AnimationActionType animationAction,
    Component::AnimationMovementType animationMovement,
    Component::AnimationDirectionType animationDirection)
{
    _elapsed += time;

    if (_elapsed >= _animationTime) {
        _elapsed -= _animationTime;
        _index++;

        Component::AnimationMovementAction key = std::make_pair(animationMovement, animationAction);

        if (_index >= _animation._animationData.at(key).size()) {
            _index = 0;
        }

        _sprite.setTexture(_animation._texture.at(_animation._animationData.at(key)[_index].first));
        _sprite.setTextureRect(_animation._animationData.at(key)[_index].second);

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