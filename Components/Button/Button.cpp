#include "Button.h"
#include <iostream>

#include <Manager/Window/WindowManager.h>

BEGIN_NAMESPACE_COMPONENT

Button::Button(float x, float y, float width, float height, const std::string& text, const sf::Font& font, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor)
    : _idleColor(idleColor)
    , _hoverColor(hoverColor)
    , _pressedColor(pressedColor)
    , _isPressed(false)
{

    _shape.setPosition(sf::Vector2f(x, y));
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(idleColor);

    _text.setString(text);
    _text.setFont(font);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(x + (width - _text.getGlobalBounds().width) / 2, y + (height - _text.getGlobalBounds().height) / 2);
}

void Button::update(const sf::Time& time)
{
}

void Button::render(sf::RenderWindow& window)
{
    window.draw(_shape);
}

void Button::mouseButtonClicked(sf::Event& event, sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    bool isMouseOver = _shape.getGlobalBounds().contains(mousePos);

    if (isMouseOver && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        _shape.setFillColor(_pressedColor);
        if (!_isPressed) {
            _isPressed = true;
            if (onClick) {
                onClick();
            }
        }
    } else if (isMouseOver) {
        _shape.setFillColor(_hoverColor);
        _isPressed = false;
    } else {
        _shape.setFillColor(_idleColor);
        _isPressed = false;
    }
}

void Button::mouseButtonReleased(sf::Event& event, sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    bool isMouseOver = _shape.getGlobalBounds().contains(mousePos);

    if (isMouseOver && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        _shape.setFillColor(_pressedColor);
        if (!_isPressed) {
            _isPressed = true;
            if (onClick) {
                onClick();
            }
        }
    } else if (isMouseOver) {
        _shape.setFillColor(_hoverColor);
        _isPressed = false;
    } else {
        _shape.setFillColor(_idleColor);
        _isPressed = false;
    }
}

void Button::setOnClick(std::function<void()> onClickFunc)
{
    onClick = std::move(onClickFunc);
}

END_NAMESPACE_COMPONENT