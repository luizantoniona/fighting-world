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
    virtual void pressedKeyEventHandler(sf::Event& event) = 0;
    virtual void releasedKeyEventHandler(sf::Event& event) = 0;

protected:
    float _healthMax;
    float _healthCurrent;
    float _manaMax;
    float _manaCurrent;

    Component::AnimationActionType _currentAnimationAction;
    Component::AnimationMovementType _currentAnimationMovement;
    Component::AnimationDirectionType _currentAnimationDirection;
    Component::Animation _animation;
};

END_NAMESPACE_COMPONENT