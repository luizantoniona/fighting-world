#pragma once

#include <functional>

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

BEGIN_NAMESPACE_COMPONENT

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& text, const sf::Font& font,
        sf::Color idleColor = sf::Color::Blue, sf::Color hoverColor = sf::Color::Green, sf::Color pressedColor = sf::Color::Red);

    void update(const sf::Time& time);
    void render(sf::RenderWindow& window);

    void mouseButtonClicked(sf::Event& event, sf::RenderWindow& window);
    void mouseButtonReleased(sf::Event& event, sf::RenderWindow& window);

    void setOnClick(std::function<void()> onClickFunc);

private:
    sf::RectangleShape _shape;
    sf::Text _text;
    sf::Color _idleColor;
    sf::Color _hoverColor;
    sf::Color _pressedColor;
    bool _isPressed;
    std::function<void()> onClick;
};

END_NAMESPACE_COMPONENT