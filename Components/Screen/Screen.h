#pragma once

#include <Components/Components_Globals.h>

#include <string>

#include <SFML/Graphics.hpp>

BEGIN_NAMESPACE_COMPONENT

class Screen
{
public:
    void setBackground();

    virtual void init() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual Screen *eventHandler(sf::RenderWindow &window, sf::Event &event) = 0;
    virtual Screen *update(sf::RenderWindow &window) = 0;

protected:
    std::string _backgroundPath;
    sf::Texture _backgroundTexture;
    sf::Sprite _backgroundSprite;
};

END_NAMESPACE_COMPONENT