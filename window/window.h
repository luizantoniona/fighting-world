#pragma once

#define GLFW_DLL
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();

private:
    GLFWwindow *_window;
};