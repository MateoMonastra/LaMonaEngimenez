#include "Window.h"

MONA_ENGIMENEZ Window::Window()
{
}

MONA_ENGIMENEZ Window::~Window()
{
}

MONA_ENGIMENEZ GLFWwindow* Window::GetWindow()
{
    return window;
}

MONA_ENGIMENEZ void Window::SetCurrent()
{
    glfwMakeContextCurrent(window);
}

MONA_ENGIMENEZ int Window::Create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
    window = glfwCreateWindow(width, height, title, monitor, share);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
}

MONA_ENGIMENEZ bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}
