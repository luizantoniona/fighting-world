#include "ResourceManager.h"

#include <fstream>
#include <iostream>

#include <json/json.h>

#include <Components/Entity/Character/CharacterHelper.h>

BEGIN_NAMESPACE_MANAGER

ResourceManager& ResourceManager::instance()
{
    static ResourceManager instance;
    return instance;
}

sf::Texture& ResourceManager::characterTexture(const Component::CharacterEnum& character, const int index)
{
    return _characterTextures.at(character).at(index);
}

std::map<Component::AnimationEnum, std::vector<sf::IntRect>>& ResourceManager::characterAnimation(const Component::CharacterEnum& character)
{
    return _characterAnmimation.at(character);
}

ResourceManager::ResourceManager()
    : _characterTextures({})
    , _characterAnmimation({})
{
    for (int i = 0; i <= static_cast<int>(Component::CharacterEnum::DENNIS); i++) {
        loadCharacter(Component::CharacterHelper().characterNameByEnum(static_cast<Component::CharacterEnum>(i)), static_cast<Component::CharacterEnum>(i));
    }
}

void ResourceManager::loadCharacterImage(const std::string& fileName, const Component::CharacterEnum& character)
{
    sf::Texture image;
    if (!image.loadFromFile(fileName)) {
        std::cout << "ResourceManager: Failed to loadCharacterImage [FILE_NAME]" << fileName << std::endl;
        return;
    }

    auto& textureList = _characterTextures[character];
    textureList.push_back(image);
}

std::map<Component::AnimationEnum, std::vector<sf::IntRect>> ResourceManager::loadCharacterAnimationData() const
{

    const auto size = sf::Vector2i(79, 79);
    const auto initSpace = sf::Vector2i(0, 0);

    auto currentStart = initSpace;

    auto nextStart = [&]() {
        currentStart.x += size.x + 1;
        if (currentStart.x > size.x * 10) {
            currentStart.x = 0;
            currentStart.y += size.y;
        }

        return currentStart;
    };

    auto character = std::map<Component::AnimationEnum, std::vector<sf::IntRect>> {};

    character[Component::AnimationEnum::STANDING].emplace_back(initSpace, size);
    character[Component::AnimationEnum::STANDING].emplace_back(nextStart(), size);
    character[Component::AnimationEnum::STANDING].emplace_back(nextStart(), size);
    character[Component::AnimationEnum::STANDING].emplace_back(nextStart(), size);

    character[Component::AnimationEnum::WALKING].emplace_back(nextStart(), size);
    character[Component::AnimationEnum::WALKING].emplace_back(nextStart(), size);
    character[Component::AnimationEnum::WALKING].emplace_back(nextStart(), size);
    character[Component::AnimationEnum::WALKING].emplace_back(nextStart(), size);

    return character;
}

void ResourceManager::loadCharacter(const std::string& characterName, const Component::CharacterEnum& characterEnum)
{
    std::cout << "ResourceManager: Loading [" << characterName << "]" << std::endl;

    const std::string jsonFileName = "Assets/Character/" + characterName + "/" + characterName + ".json";

    std::ifstream jsonFile(jsonFileName);

    Json::Value characterJson;

    jsonFile >> characterJson;

    for (Json::Value& object : characterJson["files"]) {
        loadCharacterImage(object["name"].asString(), characterEnum);
    }

    _characterAnmimation[characterEnum] = loadCharacterAnimationData();

    std::cout << "ResourceManager: Loaded [" << characterName << "]" << std::endl;
}

END_NAMESPACE_MANAGER