#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

BEGIN_NAMESPACE_COMPONENT

class Screen {
public:
    virtual void init() = 0;
    virtual void clear() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void update(const sf::Time& time) = 0;
    virtual void move(const sf::Time& time) = 0;
    virtual void pressedEventHandler(sf::Event& event) = 0;
    virtual void releasedEventHandler(sf::Event& event) = 0;
    virtual sf::Vector2f playerPosition() = 0;
};

END_NAMESPACE_COMPONENT