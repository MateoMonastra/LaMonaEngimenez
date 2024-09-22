#pragma once
#include "Exporter.h"

#include <glew.h>
#include "Window/Window.h"


#include <iostream>


const int MAX_VERTEX_COUNT = 1024;

MONA_ENGIMENEZ class Renderer
{
private:
	//static float vertices[MAX_VERTEX_COUNT];
	//static int vertexCount;

public:
	MONA_ENGIMENEZ Renderer();
	MONA_ENGIMENEZ ~Renderer();

	MONA_ENGIMENEZ static void Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	MONA_ENGIMENEZ static void SwapBuffers(Window window);
};

