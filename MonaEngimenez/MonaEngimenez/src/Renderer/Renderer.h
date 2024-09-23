#pragma once
#include "Exporter.h"

#include <glew.h>

#include <iostream>

#include "Window/Window.h"
#include "VertexArray/VertexArray.h"
#include "IndexBuffer/IndexBuffer.h"
#include "Shader/Shader.h"



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
	static float GetWidth() { return width; }
	static float GetHeight() { return height; }
};

