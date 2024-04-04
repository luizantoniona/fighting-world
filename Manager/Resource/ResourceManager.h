#pragma once

#include <Manager/Manager_Globals.h>

BEGIN_NAMESPACE_MANAGER

class ResourcesManager
{
public:
    static ResourcesManager &instance();

    ResourcesManager(const ResourcesManager &) = delete;
    ResourcesManager &operator=(const ResourcesManager &) = delete;

private:
    ResourcesManager();
};

END_NAMESPACE_MANAGER