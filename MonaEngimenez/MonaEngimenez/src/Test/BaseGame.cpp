#include "BaseGame.h"

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"
#include "Window/Window.h"

#include <iostream>
#include "glew.h"

BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

int BaseGame::TryTest()
{
	Window window;
	Renderer renderer;

	if (!glfwInit())
		return -1;

	window.Create(1024, 720, "Hello World", NULL, NULL);
	window.SetCurrent();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error";
	}

	float positions[6]
	{
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};

	renderer.GenerateBuffer(positions);

	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
