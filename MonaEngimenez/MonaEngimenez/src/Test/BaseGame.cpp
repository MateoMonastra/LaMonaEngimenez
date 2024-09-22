#include "BaseGame.h"

#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <iostream>


#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"
#include "Debugger/Debugger.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "BufferLayout/BufferLayout.h"
#include "Shader/Shader.h"
#include "Window/Window.h"
#include "Texture/Texture.h"


float positions[]
{
	-0.5f,-0.5f, 0.0f, 0.0f,
	0.5f,-0.5f, 1.0f, 0.0f,
	0.5f,0.5f, 1.0f, 1.0f,
	-0.5f,0.5f, 0.0f, 1.0f
};

unsigned int indices[]
{
	0,1,2,
	2,3,0
};

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

void SetVersion3()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
}

static float FlashingColor()
{
	static float increment = 0.05f;
	static float color = 0.0f;

	if (color > 1.0f)
	{
		increment = -0.05f;
	}
	else if (color < 0.0f)
	{
		increment = 0.05f;
	}

	return color += increment;
}

int BaseGame::TryTest()
{
	Window window;
	InitGame(window);

	Renderer renderer;
	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	IndexBuffer ib(indices, 6);
	BufferLayout layout;

	SetVersion3();
	glfwSwapInterval(1);

	DebuggerCall(glEnable(GL_BLEND));
	DebuggerCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	glm::mat4 proj = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);

	Shader shader("../MonaEngimenez/src/Shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
	shader.SetUniformMath4f("u_MVP", proj);

	Texture texture("../Assets/Milhouse.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	va.Unbind();
	shader.Unbind();
	vb.Unbind();
	ib.Unbind();


	while (!window.ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.Bind();
		shader.SetUniform4f("u_Color", FlashingColor(), 0.3f, 0.5f, 1.0f);

		renderer.Draw(va, ib, shader);

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
