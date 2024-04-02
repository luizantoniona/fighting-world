#include "window.h"

#include <Components/Screen/LoadingScreen/LoadingScreen.h>
#include <Components/Screen/LoginScreen/LoginScreen.h>
#include <Components/Screen/MenuScreen/MenuScreen.h>

BEGIN_NAMESPACE_COMPONENT

Window::Window(const int screenWidth, const int screenHeight, const std::string &displayName)
    : _currentWindow(Component::ScreenEnum::LOADING_SCREEN),
      _window(sf::VideoMode(screenWidth, screenHeight), displayName, sf::Style::Close),
      _screens({})
{
}

Component::ScreenEnum Window::currentWindow() const
{
    return _currentWindow;
}

void Window::setCurrentWindow(const Component::ScreenEnum &currentWindow)
{
    _currentWindow = currentWindow;
}

void Window::init()
{
    _screens.insert({Component::ScreenEnum::LOADING_SCREEN, new Component::LoadingScreen()});
    _screens.insert({Component::ScreenEnum::LOGIN_SCREEN, new Component::LoginScreen()});
    _screens.insert({Component::ScreenEnum::MENU_SCREEN, new Component::MenuScreen()});

    run();
}

void Window::run()
{
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
            }

            _screens.at(_currentWindow)->eventHandler(_window, event);
        }

        _screens.at(_currentWindow)->update(_window);

        _window.clear();

        _screens.at(_currentWindow)->render(_window);

        _window.display();
    }
}

END_NAMESPACE_COMPONENT