#pragma once
#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void SetClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	void Clear(int colorBuffer);
};

