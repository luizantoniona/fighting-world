#include "ResourceManager.h"

#include <iostream>

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
    loadTemplate();
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

    const auto size = sf::Vector2i(80, 80);
    const auto initSpace = sf::Vector2i(0, 0);

    auto currentStart = initSpace;

    auto nextStart = [&]() {
        currentStart.x += size.x;
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

void ResourceManager::loadTemplate()
{
    loadCharacterImage("Assets/Character/Template/template_0.png", Component::CharacterEnum::TEMPLATE);
    loadCharacterImage("Assets/Character/Template/template_1.png", Component::CharacterEnum::TEMPLATE);
    loadCharacterImage("Assets/Character/Template/template_f.png", Component::CharacterEnum::TEMPLATE);
    loadCharacterImage("Assets/Character/Template/template_s.png", Component::CharacterEnum::TEMPLATE);
    _characterAnmimation[Component::CharacterEnum::TEMPLATE] = loadCharacterAnimationData();

    std::cout << "ResourceManager: Character: Template LOADED" << std::endl;
}

END_NAMESPACE_MANAGER