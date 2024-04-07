#include "Animation.h"

#include <iostream>

BEGIN_NAMESPACE_COMPONENT

Animation::Animation(const std::map<Component::AnimationEnum, std::vector<sf::IntRect>>& animation, sf::Sprite& sprite)
    : _animation(animation)
    , _sprite(sprite)
    , _animationTime(sf::seconds(0.1))
    , _index(0)
{
}

Animation::~Animation() { }

void Animation::update(sf::Time time, std::pair<Component::AnimationEnum, Component::AnimationDirectionEnum> action)
{
    _elapsed += time;

    if (_elapsed >= _animationTime) {
        _elapsed -= _animationTime;
        _index++;

        if (_index >= _animation.at(action.first).size()) {
            _index = 0;
        }

        _sprite.setTextureRect(_animation.at(action.first)[_index]);

        updateDirection(action.second);
    }
}

void Animation::updateDirection(Component::AnimationDirectionEnum actionDirection)
{
    if ((actionDirection == Component::AnimationDirectionEnum::LEFT && _sprite.getScale().x > 0)
        || (actionDirection == Component::AnimationDirectionEnum::RIGHT && _sprite.getScale().x < 0)) {

        _sprite.scale(-1, 1);
    }
}

END_NAMESPACE_COMPONENT