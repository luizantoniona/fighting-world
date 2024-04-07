#pragma once

#include <Components/Components_Globals.h>

#include <Components/Animation/Animation.h>
#include <Components/Entity/Character/CharacterEnum.h>
#include <Components/Entity/Entity.h>

BEGIN_NAMESPACE_COMPONENT

class Character : public Entity {
public:
    Character(const sf::Vector2f& position, const CharacterEnum& character);

    void update(const sf::Time& time) override;
    void move(const sf::Time& time) override;

    void keyEventHandler(sf::Event& event) override;

private:
    Component::Animation _animation;
    Component::AnimationType _currentAnimation;
    Component::AnimationMovementType _currentAnimationMovement;
    Component::AnimationDirectionType _currentAnimationDirection;

    sf::Vector2f movement(Component::AnimationDirectionType direction) const;
};

END_NAMESPACE_COMPONENT