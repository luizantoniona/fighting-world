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
    , _currentAnimation(Component::AnimationEnum::STANDING)
    , _currentDirection(Component::AnimationDirectionEnum::RIGHT)
{
    _sprite.setTexture(Manager::ResourceManager::instance().characterTexture(character, 0));
    _sprite.setOrigin(80 / 2, 80 / 2);
}

void Character::update(const sf::Time& time)
{
    _animation.update(time, std::pair<Component::AnimationEnum, Component::AnimationDirectionEnum> { _currentAnimation, _currentDirection });
}
void Character::move(const sf::Time& time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::UP;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::LEFT;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::DOWN;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::RIGHT;

    } else {
        _currentAnimation = Component::AnimationEnum::STANDING;
        _currentDirection = Component::AnimationDirectionEnum::STAY;
    }

    _sprite.move(movement(_currentDirection) * SPEED * time.asSeconds());
}

void Character::keyEventHandler(sf::Event& event)
{
    switch (event.key.code) {
    case sf::Keyboard::Key::W:
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::UP;
        break;
    case sf::Keyboard::Key::A:
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::LEFT;
        break;
    case sf::Keyboard::Key::S:
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::DOWN;
        break;
    case sf::Keyboard::Key::D:
        _currentAnimation = Component::AnimationEnum::WALKING;
        _currentDirection = Component::AnimationDirectionEnum::RIGHT;
        break;

    default:
        break;
    }
}

sf::Vector2f Character::movement(Component::AnimationDirectionEnum direction) const
{
    static const std::map<AnimationDirectionEnum, sf::Vector2f> directionToVector = {
        { AnimationDirectionEnum::RIGHT, { 1, 0 } },
        { AnimationDirectionEnum::LEFT, { -1, 0 } },
        { AnimationDirectionEnum::UP, { 0, -1 } },
        { AnimationDirectionEnum::DOWN, { 0, 1 } },
        { AnimationDirectionEnum::STAY, { 0, 0 } }
    };
    return directionToVector.at(direction);
}

END_NAMESPACE_COMPONENT