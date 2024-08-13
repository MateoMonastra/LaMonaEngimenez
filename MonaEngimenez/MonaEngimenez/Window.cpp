#include "Window.h"

Window::Window()
{
}

Window::~Window()
{
}

int Window::Create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
    window = glfwCreateWindow(width, height, title, monitor, share);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}
