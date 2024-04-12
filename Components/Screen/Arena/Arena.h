#pragma once

#include <list>

#include <Components/Components_Globals.h>

#include <Components/Entity/Entity.h>
#include <Components/Screen/Screen.h>

BEGIN_NAMESPACE_COMPONENT

class Arena : public Screen {
public:
    Arena();
    ~Arena();

    void init() override;
    void clear() override;

    void render(sf::RenderWindow& window) override;
    void update(const sf::Time& time) override;
    void move(const sf::Time& time) override;

    void pressedEventHandler(sf::Event& event) override;
    void releasedEventHandler(sf::Event& event) override;

    sf::Vector2f playerPosition();

private:
    sf::RectangleShape _background;
    sf::RectangleShape _ground;

    std::list<Component::Entity*> _characters;
    std::list<Component::Entity*> _players;
};

END_NAMESPACE_COMPONENT