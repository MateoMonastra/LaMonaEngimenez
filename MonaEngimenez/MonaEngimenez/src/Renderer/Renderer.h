#pragma once
#include "Exporter.h"

#include <glew.h>
#include "Window/Window.h"

#include <iostream>


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
	MONA_ENGIMENEZ static void GenerateBuffer(float vertices[]);
	MONA_ENGIMENEZ static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	MONA_ENGIMENEZ static unsigned int CompileShader(unsigned int type, const std::string& source);


};

