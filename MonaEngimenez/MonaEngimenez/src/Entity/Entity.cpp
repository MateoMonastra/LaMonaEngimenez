#include "Entity.h"

Entity::Entity(Renderer* renderer, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
{
	this->renderer = renderer;
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
}

Entity::~Entity()
{
	delete[] vertexPositions;
	delete[] indices;
}
