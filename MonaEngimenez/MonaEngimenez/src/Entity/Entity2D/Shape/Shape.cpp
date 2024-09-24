#include "Shape.h"

#include "Renderer/Renderer.h"
#include "Transform/Transform.h"


void Shape::Bind(glm::mat4 mvp)
{
	shader.Bind();
	shader.SetUniform4f("u_Color", 1.0f, 0.3f, 0.5f, 1.0f);
	shader.SetUniformMath4f("u_MVP", mvp);
	shader.Unbind();
}

Shape::Shape()
{
	model = glm::mat4(1.0f);
}

void Shape::Draw(IndexBuffer ib)
{
	Renderer::Draw(va, ib, shader);
}

void Shape::Move(float x, float y)
{
	glm::mat4 mvp = Transform::Translate(model, glm::vec3(x, y, 0));
	Bind(mvp);
}

void Shape::Rotate(float angle)
{
	glm::mat4 mvp = Transform::Rotate(model, angle, width, height);
	Bind(mvp);
}

void Shape::Scale(glm::vec3 scale)
{
	glm::mat4 mvp = Transform::Scale(model, scale);
	Bind(mvp);
}
