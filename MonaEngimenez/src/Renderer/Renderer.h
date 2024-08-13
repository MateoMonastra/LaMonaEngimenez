#pragma once
#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
};

