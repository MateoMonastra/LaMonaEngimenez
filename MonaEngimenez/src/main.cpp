#include "Renderer/Renderer.h"
#include "Window/Window.h"

#include <GLFW/glfw3.h>


int main(void)
{
    Window window;
    Renderer renderer;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    window.Create(640, 480, "Hello World", NULL, NULL);

    window.SetCurrent();

    /* Loop until the user closes the window */
    while (!window.ShouldClose())
    {
        renderer.Clear(0.5f, 0.5f, 0.5f, 1.0f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}