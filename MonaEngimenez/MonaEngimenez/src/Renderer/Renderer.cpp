#include "Renderer.h"

#include "Debugger/Debugger.h"
//#include "VertexBuffer/VertexBuffer.h"
//#include "IndexBuffer/IndexBuffer.h"

float Renderer::width = 0;
float Renderer::height = 0;

void Renderer::Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetWindow());

	width = window.GetWidth();
	height = window.GetHeight();
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	shader.Bind();
	va.Bind();
	ib.Bind();

	DebuggerCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
