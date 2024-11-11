#pragma once
#include "Exporter.h"

#include <glew.h>

#include <iostream>

#include "Window/Window.h"
#include "VertexArray/VertexArray.h"
#include "IndexBuffer/IndexBuffer.h"
#include "Shader/Shader.h"
#include "VertexBuffer/VertexBuffer.h"



const int MAX_VERTEX_COUNT = 1024;

MONA_ENGIMENEZ static class Renderer
{
private:

	

public:

	static float width;
	static float height;

	static void Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	static void SwapBuffers(Window window);
	static void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	static void EnableBlending();
	static void CreateTexture(unsigned int& m_RendererID, int& m_Width, int& m_Height, unsigned char* m_LocalBuffer);
	static void BindTexture(unsigned int& m_RendererID);
	static void LoadImage(const std::string& path, unsigned int& m_RendererID, int& m_Width, int& m_Height, int& m_BPP, unsigned char* m_LocalBuffer);
	static float GetWidth() { return width; }
	static float GetHeight() { return height; }
};

