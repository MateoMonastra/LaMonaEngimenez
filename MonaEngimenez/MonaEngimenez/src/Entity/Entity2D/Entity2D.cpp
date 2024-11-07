#include "Entity2D.h"

void Entity2D::Translate(float x, float y)
{
	traslation += glm::vec3(x, y, 0);
}

void Entity2D::SetTranslation(float x, float y)
{
	traslation = glm::vec3(x, y, 0);
}

void Entity2D::Rotate(float angle)
{
	rotation += angle;
}

void Entity2D::SetRotation(float angle)
{
	rotation = angle;
}

void Entity2D::Scale(glm::vec3 scale)
{
	this->scale += scale;
}

void Entity2D::SetScale(glm::vec3 scale)
{
	this->scale = scale;
}
