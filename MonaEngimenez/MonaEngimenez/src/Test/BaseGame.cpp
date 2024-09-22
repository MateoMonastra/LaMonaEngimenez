#include "BaseGame.h"

#include "glew.h"

#include <iostream>

#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"
#include "Debugger/Debugger.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "BufferLayout/BufferLayout.h"
#include "Shader/Shader.h"


BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

void InitGame(Window& window)
{
	if (!glfwInit())
	{
		std::cout << "glf error";
	}

	window.Create(1024, 720, "Hello World", NULL, NULL);
	window.SetCurrent();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error";
	}
}

int BaseGame::TryTest()
{
	float positions[]
	{
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.5f,0.5f,
		-0.5f,0.5f
	};

	unsigned int indices[]
	{
		0,1,2,
		2,3,0
	};

	Renderer renderer;
	Window window;

	InitGame(window);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	glfwSwapInterval(1);

	VertexArray va;
	VertexBuffer vb(positions, 4 * 2 * sizeof(float));
	IndexBuffer ib(indices, 6);
	BufferLayout layout;

	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	Shader shader("../MonaEngimenez/src/Shaders/Basic.shader");
	shader.Bind();

	shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

	va.Unbind();
	shader.Unbind();
	vb.Unbind();
	ib.Unbind();

	float r = 0.0f;
	float increment = 0.05f;

	while (!window.ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.Bind();
		shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

		va.Bind();

		ib.Bind();

		DebuggerCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		if (r > 1.0f)
		{
			increment = -0.05f;
		}
		else if (r < 0.0f)
		{
			increment = 0.05f;
		}

		r += increment;

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
