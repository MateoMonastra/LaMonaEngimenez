#include "Shape.h"

#include "Renderer/Renderer.h"
#include "Transform/Transform.h"


void Shape::Bind(glm::mat4 mvp)
{
	shader.Bind();
	shader.SetUniform4f("u_Color", color.x, color.y, color.z, color.w);
	shader.SetUniformMath4f("u_MVP", mvp);
	shader.Unbind();
}

Shape::Shape()
{
	layout.Push<float>(2);

	model = glm::mat4(1.0f);
	traslation = glm::vec3(0);
	rotation = 0;
	scale = glm::vec3(1.0f);

	color = glm::vec4(1.0f, 0.3f, 0.5f, 1.0f);
}

Shape::~Shape()
{
}

void Shape::Draw()
{
	glm::mat4 mvp = Transform::TRStoMVP(traslation, rotation, scale);
	Bind(mvp);
	Renderer::Draw(va, *ib, shader);
}

void Shape::Translate(float x, float y)
{
	traslation += glm::vec3(x, y, 0);
}

void Shape::SetTranslation(float x, float y)
{
	traslation = glm::vec3(x, y, 0);
}

void Shape::Rotate(float angle)
{
	rotation += angle;
}

void Shape::SetRotation(float angle)
{
	rotation = angle;
}

void Shape::Scale(glm::vec3 scale)
{
	this->scale += scale;
}

void Shape::SetScale(glm::vec3 scale)
{
	this->scale = scale;
}

void Shape::SetColor(glm::vec4 color)
{
	this->color = color;
}
