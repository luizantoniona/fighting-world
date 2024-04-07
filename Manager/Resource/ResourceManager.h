#pragma once

#include <map>
#include <string>
#include <vector>

#include <json/json.h>

#include <SFML/graphics.hpp>

#include <Manager/Manager_Globals.h>

#include <Components/Animation/AnimationComposition.h>
#include <Components/Entity/Character/CharacterEnum.h>

BEGIN_NAMESPACE_MANAGER

class ResourceManager {
public:
    static ResourceManager& instance();

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    sf::Texture& characterTexture(const Component::CharacterEnum& character, const int index);
    Component::AnimationComposition& characterAnimation(const Component::CharacterEnum& character);

private:
    ResourceManager();
    void loadCharacterImage(const std::string& fileName, const Component::CharacterEnum& character);
    Component::AnimationComposition loadCharacterAnimationData(const Json::Value& characterJson) const;

    void loadCharacter(const std::string& characterName, const Component::CharacterEnum& characterEnum);

    std::map<Component::CharacterEnum, std::vector<sf::Texture>> _characterTextures;
    std::map<Component::CharacterEnum, Component::AnimationComposition> _characterAnmimation;
};

END_NAMESPACE_MANAGER