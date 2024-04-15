#include "WindowManager.h"

BEGIN_NAMESPACE_MANAGER

WindowManager& WindowManager::instance()
{
    static WindowManager instance;
    return instance;
}

WindowManager::WindowManager()
    : _window({})
{
    _window.init();
}

END_NAMESPACE_MANAGER