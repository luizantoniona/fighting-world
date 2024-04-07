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
void Character::move(const sf::Time& time)
{
    const bool isWalking = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

    if (isWalking) {

        _currentAnimationMovement = Component::AnimationMovementType::WALKING;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

            _currentAnimationDirection = Component::AnimationDirectionType::UP;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

                _currentAnimationDirection = Component::AnimationDirectionType::LEFT_UP;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                _currentAnimationDirection = Component::AnimationDirectionType::RIGHT_UP;
            }

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

            _currentAnimationDirection = Component::AnimationDirectionType::DOWN;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

                _currentAnimationDirection = Component::AnimationDirectionType::LEFT_DOWN;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                _currentAnimationDirection = Component::AnimationDirectionType::RIGHT_DOWN;
            }
        }

    } else {
        _currentAnimationMovement = Component::AnimationMovementType::STANDING;
        _currentAnimationDirection = Component::AnimationDirectionType::STAY;
    }

    _sprite.move(movement(_currentAnimationDirection) * SPEED * time.asSeconds());
}

void Character::keyEventHandler(sf::Event& event)
{
    switch (event.key.code) {
    default:
        break;
    }
}

sf::Vector2f Character::movement(Component::AnimationDirectionType direction) const
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