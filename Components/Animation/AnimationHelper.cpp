#include "AnimationHelper.h"

#include <map>

BEGIN_NAMESPACE_COMPONENT

AnimationMovementAction AnimationHelper::animationTypeByString(const std::string& animationString)
{
    const std::map<std::string, AnimationMovementAction> characterName = {
        { "standing", { AnimationMovementType::STANDING, AnimationActionType::STANDING } },
        { "walking", { AnimationMovementType::WALKING, AnimationActionType::STANDING } },
        { "punch", { AnimationMovementType::STANDING, AnimationActionType::PUNCHING } },
        { "jump_attack", { AnimationMovementType::JUMPING, AnimationActionType::PUNCHING } },
        { "running", { AnimationMovementType::RUNNING, AnimationActionType::STANDING } },
        { "heavy_obj_walk", { AnimationMovementType::WALKING, AnimationActionType::LEADING_HEAVY } },
        { "heavy_weapon_thw", { AnimationMovementType::STANDING, AnimationActionType::THROW_HEAVY } },
        { "jump", { AnimationMovementType::JUMPING, AnimationActionType::STANDING } }
    };

    return characterName.at(animationString);
}

END_NAMESPACE_COMPONENT