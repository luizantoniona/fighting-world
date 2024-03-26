#include "window.h"

Window::Window() : _window(nullptr)
{
    if (!glfwInit())
        return;

    _window = glfwCreateWindow(640, 480, "Mini Figter World", NULL, NULL);

    if (!_window)
    {
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(_window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(_window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

Window::~Window()
{
    glfwTerminate();
}