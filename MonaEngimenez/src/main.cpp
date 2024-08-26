#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"
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

	Shape triangle = Shape(positions);

	/* Loop until the user closes the window */
	while (!window.ShouldClose())
	{
		renderer.Clear(0.5f, 0.5f, 0.5f, 1.0f);

		glBegin(GL_TRIANGLES);

		triangle.Draw();

		glEnd();

		/* Swap front and back buffers */
		renderer.SwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}