#include "Menu.h"

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Manager/Resource/ResourceManager.h>
#include <Manager/Window/WindowManager.h>

BEGIN_NAMESPACE_COMPONENT

Menu::Menu()
{
    init();
}

Menu::~Menu()
{
    clear();
}

void Menu::init()
{
    addButton(100, 100, 200, 50, "Start Game", Manager::ResourceManager::instance().font(Component::FontEnum::ARIAL), [&]() {
        std::cout << "Start Game button clicked!" << std::endl;
    });

    addButton(100, 200, 200, 50, "Options", Manager::ResourceManager::instance().font(Component::FontEnum::ARIAL), [&]() {
        std::cout << "Options button clicked!" << std::endl;
    });
}

void Menu::clear() { }

void Menu::render(sf::RenderWindow& window)
{
    window.draw(_background);
    window.draw(_ground);

    for (auto& button : _buttons) {
        button.render(window);
    }
}

void Menu::update(const sf::Time& time)
{
    for (auto& button : _buttons) {
        button.update(time);
    }
}

void Menu::move(const sf::Time& time) { }

void Menu::pressedEventHandler(sf::Event& event) { }

void Menu::releasedEventHandler(sf::Event& event) { }

void Menu::mouseButtonClicked(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& button : _buttons) {
        button.mouseButtonClicked(event, window);
    }
}

void Menu::mouseButtonReleased(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& button : _buttons) {
        button.mouseButtonReleased(event, window);
    }
}

sf::Vector2f Menu::playerPosition()
{
    return sf::Vector2f(0, 0);
}

void Menu::addButton(float x, float y, float width, float height, const std::string& text, const sf::Font& font, std::function<void()> onClick)
{
    _buttons.emplace_back(x, y, width, height, text, font);
    _buttons.back().setOnClick(onClick);
}

END_NAMESPACE_COMPONENT