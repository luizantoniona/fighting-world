#include "AnimationHelper.h"

#include <map>

BEGIN_NAMESPACE_COMPONENT

AnimationMovementAction AnimationHelper::animationTypeByString(const std::string& animationString)
{
    const std::map<std::string, AnimationMovementAction> characterName = {
        { "standing", { AnimationMovementType::STANDING, AnimationActionType::STANDING } },
        { "walking", { AnimationMovementType::WALKING, AnimationActionType::STANDING } },
        { "running", { AnimationMovementType::RUNNING, AnimationActionType::STANDING } },
        { "falling", { AnimationMovementType::FALLING, AnimationActionType::STANDING } },
        { "jump", { AnimationMovementType::JUMPING, AnimationActionType::STANDING } },
        { "dash", { AnimationMovementType::DASHING, AnimationActionType::STANDING } },
        { "rowing", { AnimationMovementType::ROWING, AnimationActionType::STANDING } },
        { "crouch", { AnimationMovementType::CROUCHING, AnimationActionType::STANDING } },

        { "punch", { AnimationMovementType::STANDING, AnimationActionType::PUNCHING } },
        { "jump_attack", { AnimationMovementType::JUMPING, AnimationActionType::PUNCHING } },
        { "super_punch", { AnimationMovementType::WALKING, AnimationActionType::PUNCHING } },
        { "run_attack", { AnimationMovementType::RUNNING, AnimationActionType::PUNCHING } },
        { "dash_attack", { AnimationMovementType::DASHING, AnimationActionType::PUNCHING } },

        { "broken_defend", { AnimationMovementType::STANDING, AnimationActionType::DEFENDING_BROKEN } },
        { "defend", { AnimationMovementType::STANDING, AnimationActionType::DEFENDING } },

        { "picking_light", { AnimationMovementType::STANDING, AnimationActionType::PICKING_LIGHT } },
        { "picking_heavy", { AnimationMovementType::STANDING, AnimationActionType::PICKING_HEAVY } },

        { "heavy_obj_walk", { AnimationMovementType::WALKING, AnimationActionType::LEADING_HEAVY } },
        { "heavy_obj_run", { AnimationMovementType::RUNNING, AnimationActionType::LEADING_HEAVY } },
        { "heavy_weapon_thw", { AnimationMovementType::STANDING, AnimationActionType::THROW_HEAVY } },

        { "normal_weapon_atck", { AnimationMovementType::STANDING, AnimationActionType::PUNCHING_LIGHT } },
        { "jump_weapon_atck", { AnimationMovementType::JUMPING, AnimationActionType::PUNCHING_LIGHT } },
        { "run_weapon_atck", { AnimationMovementType::RUNNING, AnimationActionType::PUNCHING_LIGHT } },
        { "dash_weapon_atck", { AnimationMovementType::DASHING, AnimationActionType::PUNCHING_LIGHT } },
        { "light_weapon_thw", { AnimationMovementType::WALKING, AnimationActionType::THROW_LIGHT } },

        { "fire", { AnimationMovementType::STANDING, AnimationActionType::FIRED } },
        { "ice", { AnimationMovementType::STANDING, AnimationActionType::ICED } },

        { "stop_running", { AnimationMovementType::RUNNING_STOP, AnimationActionType::STANDING } },

        { "injured", { AnimationMovementType::STANDING, AnimationActionType::INJURED } },

        { "weapon_drink", { AnimationMovementType::STANDING, AnimationActionType::WEAPON_DRINK } },

    };

    return characterName.at(animationString);
}

// Catching/Picked_Caught/Throw_Lying_Man is actually not hardcoded. -> can discard from json

END_NAMESPACE_COMPONENT