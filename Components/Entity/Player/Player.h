#pragma once

#include <Components/Components_Globals.h>

#include <Components/Entity/Character/Character.h>

BEGIN_NAMESPACE_COMPONENT

class Player : public Character {
public:
    Player(const sf::Vector2f& position, const CharacterEnum& character);

    void move(const sf::Time& time) override;
    void keyEventHandler(sf::Event& event) override;

private:
    sf::Vector2f movement(Component::AnimationDirectionType direction) const;
};

END_NAMESPACE_COMPONENT