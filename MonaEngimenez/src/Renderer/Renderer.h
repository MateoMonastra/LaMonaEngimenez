#pragma once
#include <GLFW/glfw3.h>

class Renderer
{
public:
	void SetClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	void Clear(int colorBuffer);
};

