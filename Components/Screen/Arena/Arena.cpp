#include "Arena.h"

#include <iostream>

#include <Components/Entity/Enemy/Enemy.h>
#include <Components/Entity/Player/Player.h>

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
    Component::Entity* bandit = new Component::Enemy(sf::Vector2f(0.f, 100.f), CharacterEnum::BANDIT);
    // Component::Entity* bat = new Component::Enemy(sf::Vector2f(80.f, 100.f), CharacterEnum::BANDIT);
    // Component::Entity* davis = new Component::Enemy(sf::Vector2f(160.f, 100.f), CharacterEnum::BANDIT);
    // Component::Entity* deep = new Component::Enemy(sf::Vector2f(240.f, 100.f), CharacterEnum::BANDIT);

    _characters.insert(_characters.cbegin(), bandit);
    // _characters.insert(_characters.cbegin(), bat);
    // _characters.insert(_characters.cbegin(), davis);
    // _characters.insert(_characters.cbegin(), deep);

    Component::Entity* player = new Component::Player(sf::Vector2f(100.f, 100.f), CharacterEnum::BANDIT);

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
    for (auto& entity : _characters) {
        entity->move(time);
    }

    for (auto& entity : _players) {
        entity->move(time);
    }
}

void Arena::pressedEventHandler(sf::Event& event)
{
    for (auto& entity : _players) {
        entity->pressedKeyEventHandler(event);
    }
}

void Arena::releasedEventHandler(sf::Event& event)
{
    for (auto& entity : _players) {
        entity->releasedKeyEventHandler(event);
    }
}

void Arena::mouseButtonClicked(sf::Event& event, sf::RenderWindow& window) { }

void Arena::mouseButtonReleased(sf::Event& event, sf::RenderWindow& window) { }

sf::Vector2f Arena::playerPosition()
{
    if (!_players.empty()) {
        return _players.front()->position();
    }

    return sf::Vector2f(0, 0);
}

END_NAMESPACE_COMPONENT