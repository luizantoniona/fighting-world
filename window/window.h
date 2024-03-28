#pragma once

#include <Window/Window_Globals.h>

#include <SFML/Graphics.hpp>

BEGIN_NAMESPACE
class Window
{
public:
    Window();

    void init();
    void run();

private:
    sf::RenderWindow _window;
};

END_NAMESPACE