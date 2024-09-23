#include "Shape.h"
#include "Renderer/Renderer.h"


Shape::Shape()
{
	model = glm::mat4(1.0f);
}

void Shape::Draw(IndexBuffer ib)
{
	Renderer::Draw(va, ib, shader);
}