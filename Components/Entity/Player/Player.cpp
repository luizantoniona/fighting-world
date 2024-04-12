#include "Player.h"

#include <iostream>

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
    const bool isWalking = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

    if (isWalking) {

        _currentAnimationMovement = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ? Component::AnimationMovementType::RUNNING : Component::AnimationMovementType::WALKING;

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

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            _currentAnimationDirection = Component::AnimationDirectionType::LEFT;

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            _currentAnimationDirection = Component::AnimationDirectionType::RIGHT;
        }

    } else {
        _currentAnimationMovement = Component::AnimationMovementType::STANDING;
        _currentAnimationDirection = Component::AnimationDirectionType::STAY;
    }

    const float speed = _currentAnimationMovement == Component::AnimationMovementType::RUNNING ? RUN_SPEED : SPEED;

    _sprite.move(movement(_currentAnimationDirection) * speed * time.asSeconds());
}

void Player::pressedKeyEventHandler(sf::Event& event)
{
    switch (event.key.code) {
    case sf::Keyboard::Key::I:
        _currentAnimationAction = Component::AnimationActionType::PUNCHING;

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