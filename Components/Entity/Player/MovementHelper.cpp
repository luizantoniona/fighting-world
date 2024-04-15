#include "MovementHelper.h"

#include <map>

BEGIN_NAMESPACE_COMPONENT

Component::AnimationDirectionType MovementHelper::movementDirectionByKey(const bool isW, const bool isA, const bool isS, const bool isD)
{
    const std::vector<bool> keysPressed = { isW, isA, isS, isD };

    const std::map<std::vector<bool>, Component::AnimationDirectionType> directionsByKeys = {
        { { true, false, false, false }, Component::AnimationDirectionType::UP },
        { { false, false, true, false }, Component::AnimationDirectionType::DOWN },
        { { false, false, false, true }, Component::AnimationDirectionType::RIGHT },
        { { true, false, false, true }, Component::AnimationDirectionType::RIGHT_UP },
        { { false, false, true, true }, Component::AnimationDirectionType::RIGHT_DOWN },
        { { false, true, false, false }, Component::AnimationDirectionType::LEFT },
        { { true, true, false, false }, Component::AnimationDirectionType::LEFT_UP },
        { { false, true, true, false }, Component::AnimationDirectionType::LEFT_DOWN },
    };

    const Component::AnimationDirectionType direction = directionsByKeys.count(keysPressed) ? directionsByKeys.at(keysPressed) : Component::AnimationDirectionType::STAY;

    return direction;
}

END_NAMESPACE_COMPONENT