#include "Window.h"

Window::Window()
{
	window = nullptr;
	width = 0;
	height = 0;
}

Window::~Window()
{
}

GLFWwindow* Window::GetWindow()
{
	return window;
}

void Window::SetCurrent()
{
	glfwMakeContextCurrent(window);
}

int Window::Create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	this->width = width;
	this->height = height;

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

float Window::GetWidth()
{
	return width;
}

float Window::GetHeight()
{
	return height;
}
