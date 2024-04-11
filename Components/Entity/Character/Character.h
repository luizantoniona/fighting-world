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

    virtual void move(const sf::Time& time) = 0;
    virtual void keyEventHandler(sf::Event& event) = 0;

protected:
    Component::Animation _animation;
    Component::AnimationActionType _currentAnimationAction;
    Component::AnimationMovementType _currentAnimationMovement;
    Component::AnimationDirectionType _currentAnimationDirection;
};

END_NAMESPACE_COMPONENT