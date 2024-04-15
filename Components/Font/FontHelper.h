#pragma once

#include <string>

#include <Components/Components_Globals.h>

#include <Components/Font/FontEnum.h>

BEGIN_NAMESPACE_COMPONENT

class FontHelper {
public:
    static std::string fontByFontEnum(const Component::FontEnum& fontEnum);
};

END_NAMESPACE_COMPONENT