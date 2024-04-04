#pragma once

#include <Components/Components_Globals.h>

#include <map>

#include <SFML/Graphics.hpp>

#include <Components/Screen/Screen.h>
#include <Components/Screen/ScreenEnum.h>

BEGIN_NAMESPACE_COMPONENT

class Window
{
public:
    Window();

    Component::ScreenEnum currentWindow() const;
    void setCurrentWindow(const Component::ScreenEnum &currentWindow);

    void init();
    void run();

private:
    sf::RenderWindow _window;
    Component::ScreenEnum _currentWindow;
    std::map<Component::ScreenEnum, Component::Screen *> _screens;
};

END_NAMESPACE_COMPONENT