#pragma once

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Screen/Screen.h>

BEGIN_NAMESPACE_COMPONENT

class Loading : public Screen {
public:
    Loading();
    ~Loading();

    void init() override;
    void clear() override;

    void render(sf::RenderWindow& window) override;
    void update(const sf::Time& time) override;
    void move(const sf::Time& time) override;

    void pressedEventHandler(sf::Event& event) override;
    void releasedEventHandler(sf::Event& event) override;

    void mouseButtonClicked(sf::Event& event, sf::RenderWindow& window) override;
    void mouseButtonReleased(sf::Event& event, sf::RenderWindow& window) override;

    sf::Vector2f playerPosition() override;

private:
    sf::RectangleShape _background;
    sf::RectangleShape _ground;
};

END_NAMESPACE_COMPONENT