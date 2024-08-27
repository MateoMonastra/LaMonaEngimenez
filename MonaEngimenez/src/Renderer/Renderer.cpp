#include "Renderer.h"

int Renderer::vertexCount = 0;
float Renderer::vertices[];

MONA_ENGIMENEZ Renderer::Renderer()
{
}

MONA_ENGIMENEZ Renderer::~Renderer()
{
}

MONA_ENGIMENEZ void Renderer::Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

MONA_ENGIMENEZ void Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetWindow());
}

MONA_ENGIMENEZ void Renderer::GenerateBuffer()
{
	glewInit();

	float* verticesToBuffer = new float[vertexCount];

	for (int i = 0; i < vertexCount; i++)
	{
		verticesToBuffer[i] = vertices[i];
	}

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesToBuffer), verticesToBuffer, GL_STATIC_DRAW);

	delete[] verticesToBuffer;
}

MONA_ENGIMENEZ void Renderer::DrawArrays(BufferDirection pointer)
{
	glDrawArrays(GL_TRIANGLES, pointer.GetStart(), pointer.GetEnd());
}

MONA_ENGIMENEZ BufferDirection Renderer::AddVertices(float verticesToAdd[], int count)
{
	for (int i = 0; i < count; i++)
	{
		vertices[vertexCount + i] = verticesToAdd[i];
	}

	BufferDirection pointer;
	
	pointer.SetStart(vertexCount);
	pointer.SetEnd(vertexCount + count);

	vertexCount += count;

	return pointer;
}
