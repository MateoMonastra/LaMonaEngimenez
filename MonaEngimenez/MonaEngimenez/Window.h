#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

using namespace std;


class Window
{
private:

	GLFWwindow* window;

public:

	Window();
	~Window();

	int Create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	bool ShouldClose();
};

