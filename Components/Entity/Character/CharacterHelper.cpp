#include "CharacterHelper.h"

#include <map>

BEGIN_NAMESPACE_COMPONENT

std::string CharacterHelper::characterNameByEnum(const Component::CharacterEnum& character) const
{
    const std::map<Component::CharacterEnum, std::string> characterName = {
        { Component::CharacterEnum::TEMPLATE, "Template" },
        { Component::CharacterEnum::DAVIS, "Davis" }
    };

    return characterName.at(character);
}

END_NAMESPACE_COMPONENT