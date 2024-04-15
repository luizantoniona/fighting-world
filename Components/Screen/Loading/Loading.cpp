#include "Loading.h"

#include <iostream>

#include <Manager/Resource/ResourceManager.h>
#include <Manager/Window/WindowManager.h>

BEGIN_NAMESPACE_COMPONENT

Loading::Loading()
{
    init();
}

Loading::~Loading()
{
    clear();
}

void Loading::init()
{
    Manager::ResourceManager::instance();
}

void Loading::clear() { }

void Loading::render(sf::RenderWindow& window) { }

void Loading::update(const sf::Time& time)
{
    // Manager::WindowManager::instance().window().startGame();
}

void Loading::move(const sf::Time& time) { }

void Loading::pressedEventHandler(sf::Event& event) { }

void Loading::releasedEventHandler(sf::Event& event) { }

void Loading::mouseButtonClicked(sf::Event& event, sf::RenderWindow& window) { }

void Loading::mouseButtonReleased(sf::Event& event, sf::RenderWindow& window) { }

sf::Vector2f Loading::playerPosition()
{
    return sf::Vector2f(0, 0);
}

END_NAMESPACE_COMPONENT