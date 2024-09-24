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
#include "Entity/Entity2D/Shape/Square/Square.h"
#include "Transform/Transform.h"


static float screenWidth;
static float screenHeight;


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

static void InitGame(Window& window, float width, float height)
{
	if (!glfwInit())
	{
		std::cout << "glf error";
	}

	screenWidth = width;
	screenHeight = height;

	window.Create(screenWidth, height, "Hello World", NULL, NULL);
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
	InitGame(window, 1024, 720);

	BufferLayout layout;
	layout.Push<float>(2); //2 becouse there are 2 floats for each vertex

	Triangle triangle1(layout, 300.0f, 300.0f);

	Square square1(layout, 300.0f, 300.0f);
	square1.SetTranslation(screenWidth / 2.0f, screenHeight / 2.0f);

	Square square2(layout, 300.0f, 300.0f);
	square2.SetTranslation(screenWidth / 4.0f, screenHeight / 2.0f);


	while (!window.ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		//triangle1.Rotate(0.001f);
		triangle1.Translate(0.1f, 0.1f);
		//triangle1.Scale(glm::vec3(1.0f, 1.0f, 0.0f));

		square1.Rotate(0.001f);

		triangle1.Draw();
		square1.Draw();

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
