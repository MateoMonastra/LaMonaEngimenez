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

	unsigned int shader;

	renderer.SetShaders(shader);

	//std::string vertexShader =
	//	"#version 330 core\n"
	//	"\n"
	//	"layout(location = 0) in vec4 position"
	//	"\n"
	//	"void main()\n"
	//	"{\n"
	//	"	gl_Position = position;\n"
	//	"}\n";

	//std::string fragmentShader =
	//	"#version 330 core\n"
	//	"\n"
	//	"layout(location = 0) out vec4 color; \n"
	//	"\n"
	//	"void main()\n"
	//	"{\n"
	//	"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
	//	"}\n";

	//unsigned int shader = renderer.CreateShader(vertexShader, fragmentShader);

	//glUseProgram(shader);

	while (!window.ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	glDeleteShader(shader);

	glfwTerminate();
	return 0;
}
