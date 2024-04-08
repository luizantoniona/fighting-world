#include "Character.h"

#include <iostream>

#include <Manager/Resource/ResourceManager.h>

namespace {
constexpr const auto SPEED = 100.f;
constexpr const auto RUN_SPEED = 180.f;
}

BEGIN_NAMESPACE_COMPONENT

Character::Character(const sf::Vector2f& position, const CharacterEnum& character)
    : Entity(position)
    , _animation(Manager::ResourceManager::instance().characterAnimation(character), _sprite)
    , _currentAnimation(Component::AnimationType::IDLE)
    , _currentAnimationMovement(Component::AnimationMovementType::STANDING)
    , _currentAnimationDirection(Component::AnimationDirectionType::RIGHT)
{
    _sprite.setTexture(Manager::ResourceManager::instance().characterTexture(character, 0));
    _sprite.setOrigin(80 / 2, 80 / 2);
}

void Character::update(const sf::Time& time)
{
    _animation.update(time, _currentAnimation, _currentAnimationMovement, _currentAnimationDirection);
}

END_NAMESPACE_COMPONENT