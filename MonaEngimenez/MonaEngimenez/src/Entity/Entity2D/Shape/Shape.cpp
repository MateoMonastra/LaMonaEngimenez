#include "Shape.h"

#include "Renderer/Renderer.h"



void Shape::Bind(glm::mat4 mvp)
{
	this->shader->Bind();
	this->shader->SetUniform4f("u_Color", color.x, color.y, color.z, color.w);
	this->shader->SetUniformMath4f("u_MVP", mvp);
	this->shader->Unbind();
}

Shape::Shape()
{
	layout.Push<float>(2);

	mvp = glm::mat4(1.0f);
	traslation = glm::vec3(0);
	rotation = 0;
	scale = glm::vec3(1.0f);

	color = glm::vec4(1.0f, 0.3f, 0.5f, 1.0f);

	this->shader = Renderer::GetShapeShader();
}

Shape::~Shape()
{
}

void Shape::Draw()
{
	glm::mat4 mvp = Transform::TRStoMVP(traslation, rotation, scale);
	Bind(mvp);
	Renderer::Draw(va, *ib, m_RendererID);
}

void Shape::SetColor(glm::vec4 color)
{
	this->color = color;
}
