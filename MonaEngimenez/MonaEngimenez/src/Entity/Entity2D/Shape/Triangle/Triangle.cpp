#include "Triangle.h"

Triangle::Triangle(Renderer* renderer, glm::vec3 position, glm::vec3 scale)
	: Shape(renderer, position, scale, glm::vec3(0))
{
	vertexSize = 9;

	vertexPositions = new float[vertexSize]
		{
			-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.0f, 0.5f, 0.0f
		};

	indexSize = 3;

	indices = new int[indexSize]
		{
			0, 1, 2
		};


	renderer->CreateBuffer(vertexPositions, indices, vertexSize, indexSize, 3, VAO, VBO, EBO);
}

Triangle::~Triangle()
{
}

