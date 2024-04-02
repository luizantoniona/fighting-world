#pragma once

#include <Components/Components_Globals.h>

#include <Components/Screen/Screen.h>

BEGIN_NAMESPACE_COMPONENT

class MenuScreen : public Screen
{
public:
    MenuScreen();
    ~MenuScreen();

    void init() override;
    void render(sf::RenderWindow &window) override;
    Screen *eventHandler(sf::RenderWindow &window, sf::Event &event) override;
    Screen *update(sf::RenderWindow &window) override;
};

END_NAMESPACE_COMPONENT