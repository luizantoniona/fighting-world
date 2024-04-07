#pragma once

#include <SFML/Graphics.hpp>

#include <Components/Components_Globals.h>

#include <Components/Atoms/Animation/AnimationDirectionEnum.h>
#include <Components/Atoms/Animation/AnimationEnum.h>

BEGIN_NAMESPACE_COMPONENT

class Animation {
public:
    Animation(const std::map<Component::AnimationEnum, std::vector<sf::IntRect>>& animation, sf::Sprite& sprite);
    ~Animation();

    void update(sf::Time time, std::pair<Component::AnimationEnum, Component::AnimationDirectionEnum> action);

private:
    void updateDirection(Component::AnimationDirectionEnum actionDirection);

    const std::map<Component::AnimationEnum, std::vector<sf::IntRect>>& _animation;
    sf::Time _elapsed = {};
    sf::Time _animationTime;
    int _index;
    sf::Sprite& _sprite;
};

END_NAMESPACE_COMPONENT