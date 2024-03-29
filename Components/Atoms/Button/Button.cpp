#include "Button.h"

BEGIN_NAMESPACE_COMPONENT

Button::Button(std::string texturePath)
{
    this->buttonTexture.loadFromFile(texturePath);
    this->buttonSprite.setTexture(this->buttonTexture);
}

void Button::setButtonPosition(float x, float y)
{
    this->buttonSprite.setPosition(sf::Vector2f(x, y));
}

void Button::render(sf::RenderWindow &window)
{
    window.draw(this->buttonSprite);
}

bool Button::isButtonPressed(sf::Vector2f mousePoint)
{
    return buttonSprite.getGlobalBounds().contains(mousePoint);
}

END_NAMESPACE_COMPONENT