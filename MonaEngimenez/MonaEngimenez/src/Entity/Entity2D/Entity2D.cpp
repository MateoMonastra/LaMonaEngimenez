#include "Entity2D.h"

void Entity2D::UpdateMVP()
{
	mvp = Transform::TRStoMVP(traslation, rotation, scale);
}

void Entity2D::Translate(float x, float y)
{
	traslation += glm::vec3(x, y, 0);
	UpdateMVP();
}

void Entity2D::SetTranslation(float x, float y)
{
	traslation = glm::vec3(x, y, 0);
	UpdateMVP();
}

void Entity2D::Rotate(float angle)
{
	rotation += ToRadians(angle);
	UpdateMVP();
}

void Entity2D::SetRotation(float angle)
{
	rotation = ToRadians(angle);
	UpdateMVP();
}

void Entity2D::Scale(glm::vec3 scale)
{
	scale = glm::vec3(scale.x * scaleFactorX, scale.y * scaleFactorY, 0.0f);
	this->scale += scale;
	UpdateMVP();
}

void Entity2D::SetScale(glm::vec3 scale)
{
	//this->scale = scale;
	this->scale = glm::vec3(scale.x * scaleFactorX, scale.y * scaleFactorY, 0.0f);
	UpdateMVP();
}

float Entity2D::ToRadians(float degrees)
{
	return degrees * 3.14159f / 180.0f;
}

void Entity2D::SetScaleFactor(int FrameCountX, int FrameCountY)
{
	scaleFactorX /= FrameCountX;
	scaleFactorY /= FrameCountY;
}
