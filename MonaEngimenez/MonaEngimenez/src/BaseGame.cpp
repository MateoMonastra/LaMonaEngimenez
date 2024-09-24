#include "BaseGame.h"

#include <glew.h>

#include <iostream>

#include "Debugger/Debugger.h"

#include "Window/Window.h"

#include "Transform/Transform.h"

static float screenWidth;
static float screenHeight;

BaseGame::BaseGame(float width, float height)
{
	window = new Window();

	if (!glfwInit())
	{
		std::cout << "glf error";
	}

	screenWidth = width;
	screenHeight = height;

	window->Create(screenWidth, height, "Hello World", NULL, NULL);
	window->SetCurrent();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error";
	}

	Transform::Init();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	glfwSwapInterval(1);

	Init();
}

BaseGame::BaseGame()
{

}

BaseGame::~BaseGame()
{
	Deinit();
	glfwTerminate();
	delete window;
}

void BaseGame::Init()
{
}

void BaseGame::Update()
{
}

void BaseGame::Deinit()
{
}

void BaseGame::GameLoop()
{
	while (!window->ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		Update();

		glfwSwapBuffers(window->GetWindow());

		glfwPollEvents();
	}
}
