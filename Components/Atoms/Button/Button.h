#pragma once

#include <Components/Components_Globals.h>

#include <SFML/Graphics.hpp>
#include <string>

BEGIN_NAMESPACE_COMPONENT

class Button
{
public:
    Button(std::string);
    void setButtonPosition(float, float);
    bool isButtonPressed(sf::Vector2f);
    void render(sf::RenderWindow &);

private:
    sf::Sprite buttonSprite;
    sf::Texture buttonTexture;
};

END_NAMESPACE_COMPONENT