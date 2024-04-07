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
    Component::Entity* bandit = new Component::Character(sf::Vector2f(0.f, 100.f), CharacterEnum::BANDIT);
    Component::Entity* bat = new Component::Character(sf::Vector2f(80.f, 100.f), CharacterEnum::BANDIT);
    Component::Entity* davis = new Component::Character(sf::Vector2f(160.f, 100.f), CharacterEnum::BANDIT);
    Component::Entity* deep = new Component::Character(sf::Vector2f(240.f, 100.f), CharacterEnum::BANDIT);

    _characters.insert(_characters.cbegin(), bandit);
    _characters.insert(_characters.cbegin(), bat);
    _characters.insert(_characters.cbegin(), davis);
    _characters.insert(_characters.cbegin(), deep);

    Component::Entity* player = new Component::Character(sf::Vector2f(100.f, 100.f), CharacterEnum::BANDIT);

    _players.insert(_players.cbegin(), player);
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