#include "LoadingScreen.h"

#include <Components/Atoms/Button/Button.h>

BEGIN_NAMESPACE_COMPONENT

LoadingScreen::LoadingScreen()
{
    _backgroundPath = "win_background.jpg";
    setBackground();
}

LoadingScreen::~LoadingScreen()
{
}

void LoadingScreen::init()
{
}

void LoadingScreen::render(sf::RenderWindow &window)
{
    window.draw(_backgroundSprite);
}

Screen *LoadingScreen::eventHandler(sf::RenderWindow &window, sf::Event &event)
{
    return this;
}

Screen *LoadingScreen::update(sf::RenderWindow &window)
{
    return this;
}

END_NAMESPACE_COMPONENT