#include "ResourceManager.h"

#include <fstream>
#include <iostream>

#include <Components/Entity/Character/CharacterHelper.h>

namespace {
constexpr const char* TYPE_SPRITE = "Sprite";
constexpr const char* TYPE_FACE = "Face";
constexpr const char* TYPE_ICON = "Icon";
}

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

Component::AnimationComposition& ResourceManager::characterAnimation(const Component::CharacterEnum& character)
{
    return _characterAnmimation.at(character);
}

ResourceManager::ResourceManager()
    : _characterTextures({})
    , _characterAnmimation({})
{
    for (int i = 0; i <= static_cast<int>(Component::CharacterEnum::TEMPLATE); i++) {
        loadCharacter(Component::CharacterHelper().characterNameByEnum(static_cast<Component::CharacterEnum>(i)), static_cast<Component::CharacterEnum>(i));
    }
}

void ResourceManager::loadCharacterImage(const std::string& fileName, const Component::CharacterEnum& character)
{
    sf::Image image;
    if (!image.loadFromFile(fileName)) {
        return;
    }

    image.createMaskFromColor(sf::Color::Black, 0);

    sf::Texture texture;
    if (!texture.loadFromImage(image)) {
        std::cout << "ResourceManager: Failed to loadCharacterImage [FILE_NAME]" << fileName << std::endl;
        return;
    }

    auto& textureList = _characterTextures[character];
    textureList.push_back(texture);
}

Component::AnimationComposition ResourceManager::loadCharacterAnimationData(const Json::Value& characterJson) const
{

    auto character = Component::AnimationComposition {};

    for (Json::Value characterFile : characterJson["files"]) {

        if (characterFile["type"].asString() == TYPE_SPRITE) {

            const auto size = sf::Vector2i(80, 80);
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

            for (Json::Value characterRowInfo : characterFile["map"]) {

                if (!characterRowInfo.empty()) {

                    for (Json::Value characterColumnInfo : characterRowInfo) {

                        const char animationType = characterColumnInfo["action"].asCString()[0];
                        const char animationMovementType = characterColumnInfo["movement"].asCString()[0];

                        if (animationType != '-') {

                            Component::AnimationPair key = std::make_pair(
                                static_cast<Component::AnimationMovementType>(animationMovementType),
                                static_cast<Component::AnimationType>(animationType));

                            std::vector<sf::IntRect>& animationFrames = character._animationData[key];
                            animationFrames.emplace_back(currentStart, size);
                        }

                        nextStart();
                    }
                }
            }
        }
    }

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

    _characterAnmimation[characterEnum] = loadCharacterAnimationData(characterJson);

    std::cout << "ResourceManager: Loaded [" << characterName << "]" << std::endl;
}

END_NAMESPACE_MANAGER