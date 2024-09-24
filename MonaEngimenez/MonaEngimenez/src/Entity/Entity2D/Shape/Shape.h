#pragma once
#include "Exporter.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Entity/Entity2D/Entity2D.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "Shader/Shader.h"


MONA_ENGIMENEZ class Shape : public Entity2D
{
protected:

	glm::mat4 model;

	VertexArray va;
	VertexBuffer vb;
	Shader shader;

	float width;
	float height;

	void Bind(glm::mat4 mvp);

public:

	Shape();
	void Draw(IndexBuffer ib);

	void Move(float x, float y);
	void Rotate(float angle);
	void Scale(glm::vec3 scale);
};


