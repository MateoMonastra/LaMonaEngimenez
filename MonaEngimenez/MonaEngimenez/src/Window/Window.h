#pragma once

#include "Exporter.h"

#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;


MONA_ENGIMENEZ class Window
{
private:

	GLFWwindow* window;
	
	float width;
	float height;

public:

	Window();
	~Window();

	GLFWwindow* GetWindow();
	void SetCurrent();
	int Create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	bool ShouldClose();
	float GetWidth();
	float GetHeight();
};

