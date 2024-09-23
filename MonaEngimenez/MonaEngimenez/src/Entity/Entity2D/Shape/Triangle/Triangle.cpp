#include "Triangle.h"


#include "Renderer/Renderer.h"
#include "Transform/Transform.h"

Triangle::Triangle(BufferLayout layout, float width, float height)
{
	float positions[]
	{
		-1.0f,-1.0f,
		-1.0f,-1.0f,
		-1.0f,-1.0f,
	};

	positions[2] += width;
	positions[4] += width / 2.0f;
	positions[5] += height;

	shader.SetShader("../MonaEngimenez/src/Shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 1.0f, 0.3f, 0.5f, 1.0f);

	vb.SetVertexBuffer(positions, 4 * 2 * sizeof(float));
	va.AddBuffer(vb, layout);

	vb.Unbind();
	va.Unbind();
}

Triangle::~Triangle()
{
	shader.Unbind();
}

void Triangle::Move(float x, float y)
{
	/*glm::mat4 proj = glm::ortho(0.0f, 1024.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	model = glm::translate(glm::mat4(1.0f), glm::vec3(100, 0, 0));*/

	//glm::mat4 mvp = proj * view * model;

	glm::mat4 mvp = Transform::Translate(model, glm::vec3(x, y, 0));

	shader.Bind();
	shader.SetUniform4f("u_Color", 1.0f, 0.3f, 0.5f, 1.0f);
	shader.SetUniformMath4f("u_MVP", mvp);

	shader.Unbind();
}
