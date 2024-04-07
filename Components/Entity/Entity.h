#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

BEGIN_NAMESPACE_COMPONENT

class Entity {
public:
    Entity(const sf::Vector2f& position);

    virtual ~Entity() = default;

    virtual void draw(sf::RenderWindow& window) const;
    virtual void update(const sf::Time& time) = 0;
    virtual void move(const sf::Time& time) = 0;
    virtual void keyEventHandler(sf::Event& event) = 0;

    sf::Vector2f position() const;

protected:
    sf::Sprite _sprite;
};

END_NAMESPACE_COMPONENT