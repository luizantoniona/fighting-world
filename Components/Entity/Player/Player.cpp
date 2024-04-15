#include "Player.h"

#include <iostream>

#include <Components/Entity/Player/MovementHelper.h>

namespace {
constexpr const auto SPEED = 100.f;
constexpr const auto RUN_SPEED = 180.f;
}

BEGIN_NAMESPACE_COMPONENT

Player::Player(const sf::Vector2f& position, const CharacterEnum& character)
    : Character(position, character)
{
}

void Player::move(const sf::Time& time)
{
    const bool isWPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    const bool isAPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    const bool isSPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
    const bool isDPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

    _currentAnimationDirection = Component::MovementHelper::movementDirectionByKey(isWPressed, isAPressed, isSPressed, isDPressed);

    if (isWPressed || isAPressed || isSPressed || isDPressed) {

        _currentAnimationMovement = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ? Component::AnimationMovementType::RUNNING : Component::AnimationMovementType::WALKING;

    } else {
        _currentAnimationMovement = Component::AnimationMovementType::STANDING;
    }

    const float speed = _currentAnimationMovement == Component::AnimationMovementType::RUNNING ? RUN_SPEED : SPEED;

    _sprite.move(movement(_currentAnimationDirection) * speed * time.asSeconds());
}

void Player::pressedKeyEventHandler(sf::Event& event)
{
    switch (event.key.code) {
    case sf::Keyboard::Key::I:
        _currentAnimationAction = Component::AnimationActionType::PUNCHING;

    case sf::Keyboard::Key::Q:
        _currentAnimationMovement = Component::AnimationMovementType::JUMPING;
        break;

    default:
        _currentAnimationAction = Component::AnimationActionType::STANDING;
        break;
    }
}

void Player::releasedKeyEventHandler(sf::Event& event)
{
    switch (event.key.code) {
    default:
        _currentAnimationAction = Component::AnimationActionType::STANDING;
        break;
    }
}

sf::Vector2f Player::movement(Component::AnimationDirectionType direction) const
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