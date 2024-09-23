#pragma once
#include "Exporter.h"

#include <glew.h>

#include <iostream>

#include "Window/Window.h"
#include "VertexArray/VertexArray.h"
#include "IndexBuffer/IndexBuffer.h"
#include "Shader/Shader.h"



const int MAX_VERTEX_COUNT = 1024;

MONA_ENGIMENEZ class Renderer
{
private:
	//static float vertices[MAX_VERTEX_COUNT];
	//static int vertexCount;

public:
	MONA_ENGIMENEZ Renderer();
	MONA_ENGIMENEZ ~Renderer();

	MONA_ENGIMENEZ static void CreateBuffer(float* positions, int* indices, int positionSize, int indicesSize, int attribVertexSize, 
		unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);
	MONA_ENGIMENEZ static void Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	MONA_ENGIMENEZ static void SwapBuffers(Window window);
	MONA_ENGIMENEZ void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

