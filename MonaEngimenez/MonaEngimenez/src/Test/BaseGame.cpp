#include "BaseGame.h"

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"
#include "Debugger/Debugger.h"

#include "glew.h"
#include <iostream>

#include "Window/Window.h"

#include <gl/GL.h>


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
	Window window;
	Renderer renderer;

	InitGame(window);

	glfwSwapInterval(1);

	DebuggerCall(renderer.GenerateBuffer());

	DebuggerCall(ShaderProgramSource source = renderer.ParseShader("../MonaEngimenez/src/Shaders/Basic.shader"));

	unsigned int shader = renderer.CreateShader(source.VertexSource, source.FragmentSource);

	DebuggerCall(glUseProgram(shader));

	DebuggerCall(int location = glGetUniformLocation(shader, "u_Color"));
	ASSERT(location != -1);
	DebuggerCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f));

	float r = 0.0f;
	float increment = 0.05f;

	while (!window.ShouldClose())
	{
		DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));

		DebuggerCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));
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

	glDeleteShader(shader);

	glfwTerminate();

	return 0;
}
