#include "window.h"

#include <iostream>

#include <Components/Screen/Arena/Arena.h>

namespace {
constexpr const char* DISPLAY_NAME = "Fighting World";
constexpr const int SCREEN_WIDTH = 1000;
constexpr const int SCREEN_HEIGHT = 600;
}

BEGIN_NAMESPACE_COMPONENT

Window::Window()
    : _currentWindow(Component::ScreenEnum::ARENA)
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
    _screens.insert({ Component::ScreenEnum::ARENA, new Component::Arena() });

    _currentWindow = ScreenEnum::ARENA;

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

            // if (event.type == sf::Event::KeyPressed) {
            //     _screens.at(_currentWindow)->eventHandler(event);
            // }
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

    // centerLocation.y = SCREEN_HEIGHT / 2.f;

    // // if too close to left border
    // if (centerLocation.x < SCREEN_WIDTH / 2.f)
    //     _view.reset(sf::FloatRect(0, 0, float(SCREEN_WIDTH), float(SCREEN_HEIGHT)));

    // // if too close to rightBorder
    // else if (1200 - centerLocation.x < SCREEN_WIDTH / 2.f)
    //     _view.reset(sf::FloatRect(1200 - SCREEN_WIDTH, 0, float(SCREEN_WIDTH), float(SCREEN_HEIGHT)));

    // else
    // _view.reset(sf::FloatRect(0, 0, float(SCREEN_WIDTH), float(SCREEN_HEIGHT)));

    _view.setCenter(centerLocation);

    _window.setView(_view);
}

END_NAMESPACE_COMPONENT