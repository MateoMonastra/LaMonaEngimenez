#include "Renderer.h"

int Renderer::vertexCount = 0;
float Renderer::vertices[];

Renderer::Renderer()
{
	glewInit();
}

Renderer::~Renderer()
{
}

void Renderer::Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetWindow());
}

void Renderer::GenerateBuffer(float vertices[])
{
	//float* verticesToBuffer = new float[vertexCount];
	//
	//for (int i = 0; i < vertexCount; i++)
	//{
	//	verticesToBuffer[i] = vertices[i];
	//}

	//generated buffer id VBO
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	//select created buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	//delete[] verticesToBuffer;
}

MONA_ENGIMENEZ int Renderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
}

MONA_ENGIMENEZ unsigned int Renderer::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(GL_VERTEX_SHADER);

	const char* src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);
}
