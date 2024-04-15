#include "FontHelper.h"

#include <map>

BEGIN_NAMESPACE_COMPONENT

std::string FontHelper::fontByFontEnum(const Component::FontEnum& fontEnum)
{
    const std::map<Component::FontEnum, std::string> fonts = {
        { Component::FontEnum::ARIAL, "Assets/Fonts/arial.ttf" },
    };

    return fonts.at(fontEnum);
}

END_NAMESPACE_COMPONENT