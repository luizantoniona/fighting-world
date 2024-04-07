#pragma once

#include <map>
#include <string>
#include <vector>

#include <SFML/graphics.hpp>

#include <Manager/Manager_Globals.h>

#include <Components/Atoms/Animation/AnimationEnum.h>
#include <Components/Entity/Character/CharacterEnum.h>

BEGIN_NAMESPACE_MANAGER

class ResourceManager {
public:
    static ResourceManager& instance();

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    sf::Texture& characterTexture(const Component::CharacterEnum& character, const int index);
    std::map<Component::AnimationEnum, std::vector<sf::IntRect>>& characterAnimation(const Component::CharacterEnum& character);

private:
    ResourceManager();
    void loadCharacterImage(const std::string& fileName, const Component::CharacterEnum& character);
    std::map<Component::AnimationEnum, std::vector<sf::IntRect>> loadCharacterAnimationData() const;

    void loadTemplate();

    std::map<Component::CharacterEnum, std::vector<sf::Texture>> _characterTextures;
    std::map<Component::CharacterEnum, std::map<Component::AnimationEnum, std::vector<sf::IntRect>>> _characterAnmimation;
};

END_NAMESPACE_MANAGER