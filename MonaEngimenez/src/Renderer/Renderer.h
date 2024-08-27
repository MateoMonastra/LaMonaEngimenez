#pragma once
#include "Exporter.h"

#include <glew.h>
#include "Window/Window.h"
#include "BufferDirection/BufferDirection.h"


const int MAX_VERTEX_COUNT = 1024;

MONA_ENGIMENEZ class Renderer
{
private:
	static float vertices[MAX_VERTEX_COUNT];
	static int vertexCount;

public:
	MONA_ENGIMENEZ Renderer();
	MONA_ENGIMENEZ ~Renderer();

	MONA_ENGIMENEZ void Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	MONA_ENGIMENEZ static void SwapBuffers(Window window);
	MONA_ENGIMENEZ static void GenerateBuffer();
	MONA_ENGIMENEZ static void DrawArrays(BufferDirection pointer);
	MONA_ENGIMENEZ static BufferDirection AddVertices(float verticesToAdd[], int count);
};

