#include "Shape.h"
#include "Renderer/Renderer.h"


MONA_ENGIMENEZ Shape::Shape(float vertices[])
{
	Renderer renderer;

	for (int i = 0; i < SHAPE_VERTEX_COUNT; i++)
	{
		this->vertices[i] = vertices[i];
	}

	this->bufferDirection = renderer.AddVertices(this->vertices, SHAPE_VERTEX_COUNT);
}

MONA_ENGIMENEZ void Shape::Draw()
{
	Renderer renderer;

	renderer.DrawArrays(bufferDirection);
}