#include "Screen.h"

namespace
{
    constexpr const char *BACKGROUND_DIRECTORY = "Assets/";
}

BEGIN_NAMESPACE_COMPONENT

void Screen::setBackground()
{
    std::string address = std::string(BACKGROUND_DIRECTORY) + _backgroundPath;
    _backgroundTexture.loadFromFile(address);
    _backgroundSprite.setTexture(_backgroundTexture);
}

END_NAMESPACE_COMPONENT