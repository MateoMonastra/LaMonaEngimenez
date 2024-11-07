#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Entity2D.h"
//#include "VertexBuffer/VertexBuffer.h"
//#include "VertexArray/VertexArray.h"
//#include "IndexBuffer/IndexBuffer.h"
//#include "Shader/Shader.h"
//#include "BufferLayout/BufferLayout.h"


class MONA_ENGIMENEZ Shape : public Entity2D
{
protected:
	glm::vec4 color;

	float width;
	float height;

	void Bind(glm::mat4 mvp);

public:

	Shape();
	~Shape();
	void Draw();

	void SetColor(glm::vec4 color);
	float GetWidth() { return width; }
	float GetHeight() { return height; }
};


