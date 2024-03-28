#pragma once

#include <Components/Components_Globals.h>

#include <SFML/Graphics.hpp>

BEGIN_NAMESPACE_COMPONENT

class Window
{
public:
    Window();

    void init();
    void run();

private:
    sf::RenderWindow _window;
};

END_NAMESPACE_COMPONENT