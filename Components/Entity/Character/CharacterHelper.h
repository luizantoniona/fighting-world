#pragma once

#include <string>

#include <Components/Components_Globals.h>

#include <Components/Entity/Character/CharacterEnum.h>

BEGIN_NAMESPACE_COMPONENT

class CharacterHelper {
public:
    static std::string characterNameByEnum(const Component::CharacterEnum& character);
};

END_NAMESPACE_COMPONENT
