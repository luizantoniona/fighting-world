#include "window.h"

#include <iostream>

#include <Components/Screen/Arena/Arena.h>
#include <Components/Screen/Loading/Loading.h>
#include <Components/Screen/Menu/Menu.h>

namespace {
constexpr const char* DISPLAY_NAME = "Fighting World";
constexpr const int SCREEN_WIDTH = 1000;
constexpr const int SCREEN_HEIGHT = 600;
}

BEGIN_NAMESPACE_COMPONENT

Window::Window()
    : _currentWindow(Component::ScreenEnum::MENU)
    , _window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), DISPLAY_NAME, sf::Style::Close)
    , _screens({})
    , _clock({})
{
    _view.reset(sf::FloatRect(0, 0, float(SCREEN_WIDTH), float(SCREEN_HEIGHT)));
    _window.setView(_view);
}

Component::ScreenEnum Window::currentWindow() const
{
    return _currentWindow;
}

void Window::setCurrentWindow(const Component::ScreenEnum& currentWindow)
{
    _currentWindow = currentWindow;
}

void Window::init()
{
    startMenu();
    run();
}

void Window::run()
{
    while (_window.isOpen()) {

        adjustView();

        sf::Event event;
        while (_window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                _window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                _screens.at(_currentWindow)->pressedEventHandler(event);
            }

            if (event.type == sf::Event::KeyReleased) {
                _screens.at(_currentWindow)->releasedEventHandler(event);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                _screens.at(_currentWindow)->mouseButtonClicked(event, _window);
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                _screens.at(_currentWindow)->mouseButtonReleased(event, _window);
            }
        }

        _screens.at(_currentWindow)->move(_clock.getElapsedTime());

        _screens.at(_currentWindow)->update(_clock.getElapsedTime());

        _clock.restart();

        _window.clear();

        _screens.at(_currentWindow)->render(_window);

        _window.display();
    }
}

void Window::adjustView()
{
    auto centerLocation = _screens.at(_currentWindow)->playerPosition();

    _view.setCenter(centerLocation);

    _window.setView(_view);
}

void Window::startLoading()
{
    if (_screens.count(Component::ScreenEnum::LOADING)) {
        _screens.erase(Component::ScreenEnum::LOADING);
    }

    _screens.insert({ Component::ScreenEnum::LOADING, new Component::Loading() });

    _currentWindow = ScreenEnum::LOADING;
}

void Window::startMenu()
{
    if (_screens.count(Component::ScreenEnum::MENU)) {
        _screens.erase(Component::ScreenEnum::MENU);
    }

    _screens.insert({ Component::ScreenEnum::MENU, new Component::Menu() });

    _currentWindow = ScreenEnum::MENU;
}

void Window::startGame()
{
    if (_screens.count(Component::ScreenEnum::ARENA)) {
        _screens.erase(Component::ScreenEnum::ARENA);
    }

    _screens.insert({ Component::ScreenEnum::ARENA, new Component::Arena() });

    _currentWindow = ScreenEnum::ARENA;
}

END_NAMESPACE_COMPONENT