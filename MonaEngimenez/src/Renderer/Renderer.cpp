#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Clear(int colorBuffer)
{
	glClear(colorBuffer);
}

void Renderer::SetClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
}
