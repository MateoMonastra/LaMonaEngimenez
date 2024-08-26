#pragma once
#include <glew.h>
#include "Window/Window.h"
#include "BufferDirection/BufferDirection.h"

const int MAX_VERTEX_COUNT = 1024;

class Renderer
{
private:
	static float vertices[MAX_VERTEX_COUNT];
	static int vertexCount;

public:
	Renderer();
	~Renderer();

	void Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	static void SwapBuffers(Window window);
	static void GenerateBuffer();
	static void DrawArrays(BufferDirection pointer);
	static BufferDirection AddVertices(float verticesToAdd[], int count);
};

