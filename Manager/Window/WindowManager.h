#pragma once

#include <SFML/graphics.hpp>

#include <Manager/Manager_Globals.h>

#include <Components/Window/Window.h>

BEGIN_NAMESPACE_MANAGER

class WindowManager {
public:
    static WindowManager& instance();

    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

private:
    WindowManager();

    Component::Window _window;
};

END_NAMESPACE_MANAGER