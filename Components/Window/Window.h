#pragma once

#include <Components/Components_Globals.h>

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include <Components/Screen/Screen.h>
#include <Components/Screen/ScreenEnum.h>

BEGIN_NAMESPACE_COMPONENT

class Window
{
public:
    Window(const int screenWidth, const int screenHeight, const std::string &displayName);

    Component::ScreenEnum currentWindow() const;
    void setCurrentWindow(const Component::ScreenEnum &currentWindow);

    void init();
    void run();

private:
    Component::ScreenEnum _currentWindow;
    sf::RenderWindow _window;
    std::map<Component::ScreenEnum, Component::Screen *> _screens;
};

END_NAMESPACE_COMPONENT