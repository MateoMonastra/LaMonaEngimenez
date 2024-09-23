#pragma once
#include "Exporter.h"

#include "Renderer/Renderer.h"

#include <glm.hpp>


MONA_ENGIMENEZ class Entity
{
protected:

	Renderer* renderer;

	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	int vertexSize;
	int attribPosSize = 3;
	int attribColorSize = 4;

	float* vertexPositions;
	int* indices;
	int indexSize;

public:

	Entity(Renderer* renderer, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation);
	~Entity();

	MONA_ENGIMENEZ virtual void Draw() = 0;
};

