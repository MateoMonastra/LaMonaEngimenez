#pragma once
#include "Exporter.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "Entity/Entity.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "Shader/Shader.h"


MONA_ENGIMENEZ class Entity2D : public Entity
{
protected:

	glm::mat4 model;

	VertexArray va;
	VertexBuffer vb;
	Shader shader;
	
	glm::vec3 traslation;
	float rotation;
	glm::vec3 scale;

	float width;
	float height;


public:

	virtual void Draw() = 0;
};