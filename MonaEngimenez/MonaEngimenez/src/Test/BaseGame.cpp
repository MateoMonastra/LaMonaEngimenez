#include "BaseGame.h"

#include <glew.h>

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
#include "Entity/Entity2D/Shape/Triangle/Triangle.h"
#include "Transform/Transform.h"


unsigned int indices[]
{
	0,1,2,
	//2,3,0
};

BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

void SetVersion3()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
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

	Transform::Init();

	SetVersion3();
	glfwSwapInterval(1);
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

	IndexBuffer ib(indices, 3);//6 becouse there are 6 indices for 2 triangles
	BufferLayout layout;
	layout.Push<float>(2); //2 becouse there are 2 floats for each vertex

	Triangle triangle1(layout, 300.0f, 300.0f);

	ib.Unbind();

	while (!window.ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		triangle1.Rotate(0.1f);
		triangle1.Move(0.1f, 0.1f);
		//triangle1.Scale(glm::vec3(1.0f, 1.0f, 0.0f));

		triangle1.Draw(ib);

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
