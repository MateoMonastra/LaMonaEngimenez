#pragma once
#include "Exporter.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Entity/Entity.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "Shader/Shader.h"
#include "IndexBuffer/IndexBuffer.h"
#include "BufferLayout/BufferLayout.h"
#include "Transform/Transform.h"



class MONA_ENGIMENEZ Entity2D : public Entity
{
protected:
	VertexArray va;
	VertexBuffer vb;
	Shader shader;
	IndexBuffer* ib;
	BufferLayout layout;

	int scaleFactorX = 1;
	int scaleFactorY = 1;

	glm::mat4 mvp;
	
	float m_Alpha = 1.0f;
	glm::vec3 traslation;
	float rotation;
	glm::vec3 scale;
	float translationSpeed = 100.0f;
	float rotationSpeed = 100.0f;
	float scaleSpeed = 1.0f;

	void UpdateMVP();

public:

	void Translate(float x, float y);
	void SetTranslation(float x, float y);
	void Rotate(float angle);
	void SetRotation(float angle);
	void Scale(glm::vec3 scale);
	void SetScale(glm::vec3 scale);
	void SetAlpha(float alpha);
	void UpdateAlpha(float alpha);
	float ToRadians(float degrees);
	void SetScaleFactor(int FrameCountX, int FrameCountY);
	void UpdateTransform(glm::vec2 direction, float rotation, glm::vec2 scale);

	glm::vec3 GetScale() { return scale; }
	glm::vec3 GetTranslation() { return traslation; }

	virtual void Draw() = 0;
};