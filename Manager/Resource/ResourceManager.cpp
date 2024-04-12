#include "ResourceManager.h"

#include <fstream>
#include <iostream>

#include <Components/Animation/AnimationHelper.h>
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

Component::AnimationData& ResourceManager::characterAnimation(const Component::CharacterEnum& character)
{
    return _characterAnimation.at(character);
}

ResourceManager::ResourceManager()
    : _characterAnimation({})
{
    for (int i = 0; i <= static_cast<int>(Component::CharacterEnum::BANDIT); i++) {
        loadCharacter(Component::CharacterHelper().characterNameByEnum(static_cast<Component::CharacterEnum>(i)), static_cast<Component::CharacterEnum>(i));
    }
}

void ResourceManager::loadCharacter(const std::string& characterName, const Component::CharacterEnum& characterEnum)
{
    std::cout << "ResourceManager: Loading [" << characterName << "]" << std::endl;

    const std::string jsonFileName = "Assets/Character/" + characterName + "/" + characterName + ".json";

    std::ifstream jsonFile(jsonFileName);

    Json::Value characterJson;

    jsonFile >> characterJson;

    loadCharacterAnimationData(characterJson, characterEnum);

    std::cout << "ResourceManager: Loaded [" << characterName << "]" << std::endl;
}

void ResourceManager::loadCharacterAnimationData(const Json::Value& characterJson, const Component::CharacterEnum& characterEnum)
{
    int imageIndex = 0;

    for (Json::Value characterFile : characterJson["files"]) {

        if (characterFile["type"].asString() == TYPE_SPRITE) {

            loadCharacterImage(characterFile["name"].asString(), characterEnum);

            const auto size = sf::Vector2i(characterFile["characterW"].asInt() + 1, characterFile["characterH"].asInt() + 1);
            const auto initSpace = sf::Vector2i(0, 0);

            auto currentStart = initSpace;

            auto nextStart = [&]() {
                currentStart.x += size.x;
                if (currentStart.x >= size.x * 10) {
                    currentStart.x = 0;
                    currentStart.y += size.y;
                }

                return currentStart;
            };

            for (Json::Value characterRowInfo : characterFile["map"]) {

                if (!characterRowInfo.empty()) {

                    for (Json::Value characterColumnInfo : characterRowInfo) {

                        const std::string animationString = characterColumnInfo["state"].asString();

                        if (animationString[0] != '-' && !animationString.empty()) {

                            Component::AnimationData& characterAnimation = _characterAnimation[characterEnum];

                            Component::AnimationMovementAction key = Component::AnimationHelper::animationTypeByString(animationString);

                            Component::AnimationTextureRectangle& value = characterAnimation._animationData[key];

                            value.push_back(std::make_pair(imageIndex, sf::IntRect(currentStart, size)));
                        }

                        nextStart();
                    }
                }
            }

            imageIndex++;
        }
    }
}

void ResourceManager::loadCharacterImage(const std::string& fileName, const Component::CharacterEnum& characterEnum)
{
    sf::Texture texture;
    if (!texture.loadFromFile(fileName)) {
        std::cout << "ResourceManager: Failed to loadCharacterImage [FILE_NAME]" << fileName << std::endl;
        return;
    }

    auto& characterAnimation = _characterAnimation[characterEnum];

    characterAnimation._texture.push_back(texture);
}

END_NAMESPACE_MANAGER