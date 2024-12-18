#include "BaseGame.h"

#include <glew.h>
#include <iostream>

#include "Debugger/Debugger.h"
#include "Window/Window.h"
#include "Transform/Transform.h"
#include "Timer/Time.h"
#include "Renderer/Renderer.h"


BaseGame::BaseGame(float width, float height)
{
	window = new Window();

	if (!glfwInit())
	{
		std::cout << "glf error";
	}

	screenWidth = width;
	screenHeight = height;

	screenCenterX = screenWidth / 2.0f;
	screenCenterY = screenHeight / 2.0f;

	window->Create(screenWidth, height, "Hello World", NULL, NULL);
	window->SetCurrent();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error";
	}

	Transform::Init();
	Time::setTime();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	Renderer::LoadShader();
	Renderer::EnableBlending();
	

	glfwSwapInterval(1);

	inputManager = new InputManager(window->GetWindow());
}

BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
	delete window; 
	delete inputManager;
	glfwTerminate();
}

void BaseGame::GameLoop()
{
	while (!window->ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		Update();

		glfwSwapBuffers(window->GetWindow());

		glfwPollEvents();

		Time::setTime();
	}

}
