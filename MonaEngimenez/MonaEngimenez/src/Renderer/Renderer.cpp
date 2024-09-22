#include "Renderer.h"


#include "Debugger/Debugger.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetWindow());
}