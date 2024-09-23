#include "BaseGame.h"

#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <imgui.h>
#include <Implementations/imgui_impl_glfw.h>
#include <Implementations/imgui_impl_opengl3.h>

#include <iostream>

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Shape/Shape.h"
#include "Debugger/Debugger.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "BufferLayout/BufferLayout.h"
#include "Shader/Shader.h"
#include "Window/Window.h"
#include "Texture/Texture.h"



const float screenWidth = 1024.0f;
const float screenHeight = 720.0f;

glm::vec2 center = { screenWidth / 2, screenHeight / 2 };

glm::vec2 bottomLeft = { 100.0f, 100.0f };
glm::vec2 bottomRight = { 300.0f, 100.0f };
glm::vec2 topRight = { 300.0f, 300.0f };
glm::vec2 topLeft = { 100.0f, 300.0f };

float positions[]
{
	bottomLeft.x,bottomLeft.y, 0.0f, 0.0f,
	bottomRight.x,bottomRight.y, 1.0f, 0.0f,
	topRight.x,topRight.y, 1.0f, 1.0f,
	topLeft.x,topLeft.y, 0.0f, 1.0f
};

unsigned int indices[]
{
	0,1,2,
	2,3,0
};

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

	window.Create(screenWidth, screenHeight, "Hello World", NULL, NULL);
	window.SetCurrent();

	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew error";
	}
}

void SetVersion3()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
}

static float FlashingColor()
{
	static float increment = 0.05f;
	static float color = 0.0f;

	if (color > 1.0f)
	{
		increment = -0.05f;
	}
	else if (color < 0.0f)
	{
		increment = 0.05f;
	}

	return color += increment;
}

int BaseGame::TryTest()
{
	Window window;
	InitGame(window);

	Renderer renderer;
	VertexArray va;
	VertexBuffer vb(positions, 4 * 4 * sizeof(float));
	IndexBuffer ib(indices, 6);
	BufferLayout layout;

	SetVersion3();
	glfwSwapInterval(1);

	DebuggerCall(glEnable(GL_BLEND));
	DebuggerCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	glm::mat4 proj = glm::ortho(0.0f, screenWidth, 0.0f, screenHeight, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

	glm::mat4 mvp = proj * view * model;

	Shader shader("../MonaEngimenez/src/Shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
	shader.SetUniformMath4f("u_MVP", mvp);

	Texture texture("../Assets/Milhouse.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	va.Unbind();
	shader.Unbind();
	vb.Unbind();
	ib.Unbind();


	auto context = ImGui::CreateContext();
	ImGui::SetCurrentContext(context);

	const char* glsl_version = "#version 130";
	ImGui_ImplGlfw_InitForOpenGL(window.GetWindow(), true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	

	ImGui::StyleColorsDark();


	while (!window.ShouldClose())
	{
		renderer.Clear(0.2f, 0.3f, 0.8f, 1.0f);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		shader.Bind();
		shader.SetUniform4f("u_Color", FlashingColor(), 0.3f, 0.5f, 1.0f);

		renderer.Draw(va, ib, shader);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window.GetWindow());

		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();

	return 0;
}
