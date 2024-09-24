#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Entity2D.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "IndexBuffer/IndexBuffer.h"
#include "Shader/Shader.h"


MONA_ENGIMENEZ class Shape : public Entity2D
{
protected:

	glm::mat4 model;

	VertexArray va;
	VertexBuffer vb;
	Shader shader;
	IndexBuffer* ib;
	glm::vec4 color;

	float width;
	float height;

	void Bind(glm::mat4 mvp);

public:

	Shape();
	~Shape();
	void Draw();

	void Translate(float x, float y);
	void SetTranslation(float x, float y);
	void Rotate(float angle);
	void SetRotation(float angle);
	void Scale(glm::vec3 scale);
	void SetScale(glm::vec3 scale);
	void SetColor(glm::vec4 color);
};


