#include "ResourceManager.h"

BEGIN_NAMESPACE_MANAGER

ResourcesManager &ResourcesManager::instance()
{
    static ResourcesManager instance;
    return instance;
}

ResourcesManager::ResourcesManager()
{
    // TODO: CREATE METHODS TO LOAD DATA
}

END_NAMESPACE_MANAGER