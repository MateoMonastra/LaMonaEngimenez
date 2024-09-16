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

MONA_ENGIMENEZ void BaseGame::InitGame(Window& window)
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

	unsigned int shader;

	//renderer.SetShaders(shader);

	ShaderProgramSource source = renderer.ParseShader("src/Shaders/Basic.shader");
	std::cout << "VERTEX" << std::endl;
	std::cout << source.VertexSource << std::endl;
	std::cout << "FRAGMENT" << std::endl;
	std::cout << source.FragmentSource << std::endl;

	shader = renderer.CreateShader(source.VertexSource, source.FragmentSource);

	glUseProgram(shader);

	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glDeleteProgram(shader);

	glfwTerminate();

	return 0;
}
