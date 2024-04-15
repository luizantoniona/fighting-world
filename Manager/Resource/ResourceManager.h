#pragma once

#include <map>
#include <string>
#include <vector>

#include <json/json.h>

#include <SFML/graphics.hpp>

#include <Manager/Manager_Globals.h>

#include <Components/Animation/AnimationData.h>
#include <Components/Entity/Character/Character.h>
#include <Components/Entity/Character/CharacterEnum.h>
#include <Components/Font/FontEnum.h>

BEGIN_NAMESPACE_MANAGER

class ResourceManager {
public:
    static ResourceManager& instance();

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    sf::Font& font(const Component::FontEnum& font);
    Component::AnimationData& characterAnimation(const Component::CharacterEnum& character);

private:
    ResourceManager();

    void loadFont(const Component::FontEnum& fontEnum);

    void loadCharacter(const std::string& characterName, const Component::CharacterEnum& characterEnum);
    void loadCharacterAnimationData(const Json::Value& characterJson, const Component::CharacterEnum& characterEnum);
    void loadCharacterImage(const std::string& fileName, const Component::CharacterEnum& characterEnum);

    std::map<Component::FontEnum, sf::Font> _fonts;
    std::map<Component::CharacterEnum, Component::AnimationData> _characterAnimation;
};

END_NAMESPACE_MANAGER