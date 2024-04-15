#pragma once

#include <list>

#include <Components/Components_Globals.h>

#include <Components/Button/Button.h>
#include <Components/Screen/Screen.h>

BEGIN_NAMESPACE_COMPONENT

class Menu : public Screen {
public:
    Menu();
    ~Menu();

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

    void addButton(float x, float y, float width, float height, const std::string& text, const sf::Font& font, std::function<void()> onClick);

private:
    sf::RectangleShape _background;
    sf::RectangleShape _ground;
    std::list<Button> _buttons;
};

END_NAMESPACE_COMPONENT