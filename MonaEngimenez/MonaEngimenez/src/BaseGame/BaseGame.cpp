#include "BaseGame.h"

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"

#include <iostream>




BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

void InitGame(Window& window)
{
	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error";
	}

	if (!glfwInit())
	{
		std::cout << "glf error";
	}

	window.Create(1024, 720, "Hello World", NULL, NULL);
	window.SetCurrent();
}

int BaseGame::TryTest()
{
	Window window;
	Renderer renderer;

	InitGame(window);

	float positions[6]
	{
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};

	renderer.GenerateBuffer(positions);

	ShaderProgramSource source = renderer.ParseShader("../MonaEngimenez/src/Shaders/Basic.shader");
	std::cout << "VERTEX" << std::endl;
	std::cout << source.VertexSource << std::endl;
	std::cout << "FRAGMENT" << std::endl;
	std::cout << source.FragmentSource << std::endl;

	unsigned int shader = renderer.CreateShader(source.VertexSource, source.FragmentSource);

	glUseProgram(shader);

	Update(window);

	glDeleteShader(shader);

	glfwTerminate();

	return 0;
}

MONA_ENGIMENEZ void BaseGame::Update(Window& window)
{
	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}
}
