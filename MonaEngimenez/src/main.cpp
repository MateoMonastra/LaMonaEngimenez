#include <glew.h>
#include <GLFW/glfw3.h>

#include "Renderer/Renderer.h"
#include "Window/Window.h"



int main(void)
{
	Window window;
	Renderer renderer;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	window.Create(640, 480, "Hello World", NULL, NULL);

	window.SetCurrent();

	float positions[6]
	{
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f

	};

		/* Loop until the user closes the window */
		while (!window.ShouldClose())
		{
			renderer.Clear(0.5f, 0.5f, 0.5f, 1.0f);

			glBegin(GL_TRIANGLES);

			glColor3f(0.5, 0, 0);

			unsigned int buffer;
			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ARRAY_BUFFER, buffer);
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions,GL_STATIC_DRAW);

			glEnd();

			/* Swap front and back buffers */
			glfwSwapBuffers(window.GetWindow());

			/* Poll for and process events */
			glfwPollEvents();
		}

	glfwTerminate();
	return 0;
}