#include "Entity2D.h"

#include "Timer/Timer.h"

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
	this->scale = glm::vec3(scale.x * scaleFactorX, scale.y * scaleFactorY, 0.0f);
	UpdateMVP();
}

void Entity2D::SetAlpha(float alpha)
{
	m_Alpha = alpha;
	shader.SetUniform1f("u_Alpha", m_Alpha);
}

void Entity2D::UpdateAlpha(float alpha)
{
	m_Alpha += alpha;

	if (m_Alpha > 1.0f)
	{
		m_Alpha = 1.0f;
	}
	else if (m_Alpha < 0.0f)
	{
		m_Alpha = 0.0f;
	}	

	shader.SetUniform1f("u_Alpha", m_Alpha);
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

void Entity2D::UpdateTransform(glm::vec2 direction, float rotation, glm::vec2 scale)
{
	traslation += glm::vec3(direction.x, direction.y, 0.0f) * translationSpeed;
	this->rotation += ToRadians(rotation) * rotationSpeed;

	this->scale.x += scale.x * scaleFactorX * scaleSpeed;;
	this->scale.y += scale.y * scaleFactorY * scaleSpeed;;

	UpdateMVP();
}
