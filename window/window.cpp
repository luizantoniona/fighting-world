#include "window.h"

BEGIN_NAMESPACE

Window::Window() : _window(sf::VideoMode(800, 600), "MFW", sf::Style::Close)
{
}

void Window::run()
{
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        _window.clear();
        _window.display();
    }
}

END_NAMESPACE