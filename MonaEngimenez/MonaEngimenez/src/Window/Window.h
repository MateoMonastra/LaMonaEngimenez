#pragma once

#include "Exporter.h"

#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;


MONA_ENGIMENEZ class Window
{
private:

	GLFWwindow * window;

public:

	MONA_ENGIMENEZ Window();
	MONA_ENGIMENEZ ~Window();

	MONA_ENGIMENEZ GLFWwindow* GetWindow();
	MONA_ENGIMENEZ void SetCurrent();
	MONA_ENGIMENEZ int Create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	MONA_ENGIMENEZ bool ShouldClose();
};

