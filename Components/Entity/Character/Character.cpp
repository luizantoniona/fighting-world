#include "Character.h"

#include <iostream>

#include <Manager/Resource/ResourceManager.h>

BEGIN_NAMESPACE_COMPONENT

Character::Character(const sf::Vector2f& position, const CharacterEnum& character)
    : Entity(position)
    , _animation(Manager::ResourceManager::instance().characterAnimation(character), _sprite)
    , _currentAnimation(Component::AnimationEnum::STANDING)
    , _currentDirection(Component::AnimationDirectionEnum::RIGHT)
{
    _sprite.setTexture(Manager::ResourceManager::instance().characterTexture(character, 0));
    //_sprite.setOrigin(_sprite.getLocalBounds().height / 2, _sprite.getLocalBounds().width / 2);
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
    }
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

END_NAMESPACE_COMPONENT