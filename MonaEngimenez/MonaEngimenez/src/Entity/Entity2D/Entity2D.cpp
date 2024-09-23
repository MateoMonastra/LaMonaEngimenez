#include "Entity2D.h"

Entity2D::Entity2D(Renderer* renderer, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
	: Entity(renderer, position, scale, rotation)
{
}

Entity2D::~Entity2D()
{
}
