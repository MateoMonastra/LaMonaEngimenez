#include "Renderer.h"

#include "Debugger/Debugger.h"
#include "vendor/stb_image.h"

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

void Renderer::EnableBlending()
{
	DebuggerCall(glEnable(GL_BLEND));
	DebuggerCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA))
}

void Renderer::CreateTexture(unsigned int& m_RendererID, int& m_Width, int& m_Height, unsigned char* m_LocalBuffer)
{
	DebuggerCall(glGenTextures(1, &m_RendererID));
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	glGenerateMipmap(GL_TEXTURE_2D);

	DebuggerCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);

	BindTexture(m_RendererID);
}

void Renderer::BindTexture(unsigned int& m_RendererID)
{
	DebuggerCall(glActiveTexture(GL_TEXTURE0));
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Renderer::LoadImage(const std::string& path, unsigned int& m_RendererID, int& m_Width, int& m_Height, int& m_BPP, unsigned char* m_LocalBuffer)
{
	EnableBlending();

	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	CreateTexture(m_RendererID, m_Width, m_Height, m_LocalBuffer);
}
