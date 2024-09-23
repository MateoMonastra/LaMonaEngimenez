#include "Shape.h"
#include "Renderer/Renderer.h"


Shape::Shape()
{
}

void Shape::Draw(IndexBuffer ib)
{
	Renderer::Draw(va, ib, shader);
}