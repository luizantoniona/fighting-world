#include "window.h"

namespace
{
    constexpr const char *DISPLAY_NAME = "Fighting World";
    constexpr const int SCREEN_WIDTH = 800;
    constexpr const int SCREEN_HEIGHT = 600;
}

BEGIN_NAMESPACE_COMPONENT

Window::Window()
    : _currentWindow(Component::ScreenEnum::ARENA),
      _window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), DISPLAY_NAME, sf::Style::Close),
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
    //_screens.insert({Component::ScreenEnum::LOADING_SCREEN, new Component::LoadingScreen()});
    //_screens.insert({Component::ScreenEnum::LOGIN_SCREEN, new Component::LoginScreen()});
    //_screens.insert({Component::ScreenEnum::MENU_SCREEN, new Component::MenuScreen()});

    run();
}

void Window::run()
{
    while (_window.isOpen())
    {
        _window.clear();

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

        _screens.at(_currentWindow)->render(_window);

        _window.display();
    }
}

END_NAMESPACE_COMPONENT