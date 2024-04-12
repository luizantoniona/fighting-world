#include "Enemy.h"

#include <iostream>

namespace {
constexpr const auto SPEED = 100.f;
constexpr const auto RUN_SPEED = 180.f;
}

BEGIN_NAMESPACE_COMPONENT

Enemy::Enemy(const sf::Vector2f& position, const CharacterEnum& character)
    : Character(position, character)
{
}

void Enemy::move(const sf::Time& time)
{
    //_sprite.move(movement(_currentAnimationDirection) * SPEED * time.asSeconds());
}

void Enemy::pressedKeyEventHandler(sf::Event& event) { }

void Enemy::releasedKeyEventHandler(sf::Event& event) { }

sf::Vector2f Enemy::movement(Component::AnimationDirectionType direction) const
{
    static const std::map<AnimationDirectionType, sf::Vector2f> directionToVector = {
        { AnimationDirectionType::RIGHT, { 1, 0 } },
        { AnimationDirectionType::RIGHT_UP, { 1, -1 } },
        { AnimationDirectionType::RIGHT_DOWN, { 1, 1 } },
        { AnimationDirectionType::LEFT, { -1, 0 } },
        { AnimationDirectionType::LEFT_UP, { -1, -1 } },
        { AnimationDirectionType::LEFT_DOWN, { -1, 1 } },
        { AnimationDirectionType::UP, { 0, -1 } },
        { AnimationDirectionType::DOWN, { 0, 1 } },
        { AnimationDirectionType::STAY, { 0, 0 } }
    };
    return directionToVector.at(direction);
}

END_NAMESPACE_COMPONENT