#pragma once
#include "Exporter.h"

#include <glew.h>
#include "Window/Window.h"


#include <iostream>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

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
	MONA_ENGIMENEZ static void GenerateBuffer(unsigned int& VAO, unsigned int& shader, int& location);
	MONA_ENGIMENEZ static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	MONA_ENGIMENEZ static unsigned int CompileShader(unsigned int type, const std::string& source);
	MONA_ENGIMENEZ static ShaderProgramSource ParseShader(const std::string& filepath);
};

