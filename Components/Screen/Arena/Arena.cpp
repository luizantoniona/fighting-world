#include "Arena.h"

#include <iostream>

#include <Components/Entity/Character/Character.h>

BEGIN_NAMESPACE_COMPONENT

Arena::Arena()
{
    init();
}

Arena::~Arena()
{
    clear();
}

void Arena::init()
{
    // Component::Entity* teste = new Component::Character(sf::Vector2f(100.f, 100.f), CharacterEnum::TEMPLATE);

    Component::Entity* player = new Component::Character(sf::Vector2f(0.f, 0.f), CharacterEnum::TEMPLATE);

    // _characters.insert(_characters.cbegin(), teste);

    _players.insert(_players.cbegin(), player);

    //_characters.insert(_characters.cbegin(), dynamic_cast<Component::Entity
    //*>(teste));
}

void Arena::clear()
{
    // TODO CLEAR LISTS
}

void Arena::render(sf::RenderWindow& window)
{
    for (auto& entity : _characters) {
        entity->draw(window);
    }

    for (auto& entity : _players) {
        entity->draw(window);
    }
}

void Arena::update(const sf::Time& time)
{
    for (auto& entity : _characters) {
        entity->update(time);
    }

    for (auto& entity : _players) {
        entity->update(time);
    }
}

void Arena::move(const sf::Time& time)
{
    for (auto& entity : _players) {
        entity->move(time);
    }
}

void Arena::eventHandler(sf::Event& event)
{
    for (auto& entity : _players) {
        entity->keyEventHandler(event);
    }
}

sf::Vector2f Arena::playerPosition()
{
    if (!_players.empty()) {
        return _players.front()->position();
    }

    return sf::Vector2f(0, 0);
}

END_NAMESPACE_COMPONENT