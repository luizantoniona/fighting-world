#include "CharacterHelper.h"

#include <map>

BEGIN_NAMESPACE_COMPONENT

std::string CharacterHelper::characterNameByEnum(const Component::CharacterEnum& character) const
{
    const std::map<Component::CharacterEnum, std::string> characterName = {
        { Component::CharacterEnum::BANDIT, "Bandit" },
        { Component::CharacterEnum::BAT, "Bat" },
        { Component::CharacterEnum::DAVIS, "Davis" },
        { Component::CharacterEnum::DEEP, "Deep" },
        { Component::CharacterEnum::DENNIS, "Dennis" },
        { Component::CharacterEnum::FIREN, "Firen" },
        { Component::CharacterEnum::FIRZEN, "Firzen" },
        { Component::CharacterEnum::FREEZE, "Freeze" },
        { Component::CharacterEnum::HENRY, "Henry" },
        { Component::CharacterEnum::HUNTER, "Hunter" },
        { Component::CharacterEnum::JACK, "Jack" },
        { Component::CharacterEnum::JAN, "Jan" },
        { Component::CharacterEnum::JOHN, "John" },
        { Component::CharacterEnum::JULIAN, "Julian" },
        { Component::CharacterEnum::JUSTIN, "Justin" },
        { Component::CharacterEnum::KNIGHT, "Knight" },
        { Component::CharacterEnum::LOUIS, "Louis" },
        { Component::CharacterEnum::LOUISEX, "LouisEX" },
        { Component::CharacterEnum::MARK, "Mark" },
        { Component::CharacterEnum::MONK, "Monk" },
        { Component::CharacterEnum::RUDOLF, "Rudolf" },
        { Component::CharacterEnum::SORCERER, "Sorcerer" },
        { Component::CharacterEnum::WOODY, "Woody" },
        { Component::CharacterEnum::TEMPLATE, "Template" },
    };

    return characterName.at(character);
}

END_NAMESPACE_COMPONENT