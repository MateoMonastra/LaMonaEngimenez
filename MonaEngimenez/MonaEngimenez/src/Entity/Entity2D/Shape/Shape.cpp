#include "Shape.h"


Shape::Shape(float vertices[])
{
	for (int i = 0; i < SHAPE_VERTEX_COUNT; i++)
	{
		this->vertices[i] = vertices[i];
	}
}

void Shape::Draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}