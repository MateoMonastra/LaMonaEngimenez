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
	
	glm::vec3 traslation;
	float rotation;
	glm::vec3 scale;

	void UpdateMVP();

public:

	void Translate(float x, float y);
	void SetTranslation(float x, float y);
	void Rotate(float angle);
	void SetRotation(float angle);
	void Scale(glm::vec3 scale);
	void SetScale(glm::vec3 scale);

	virtual void Draw() = 0;
};