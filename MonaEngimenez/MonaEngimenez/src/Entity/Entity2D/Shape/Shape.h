#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Entity2D.h"
#include "VertexBuffer/VertexBuffer.h"
#include "VertexArray/VertexArray.h"
#include "Shader/Shader.h"


MONA_ENGIMENEZ class Shape : public Entity2D
{
protected:

	VertexArray va;
	VertexBuffer vb;
	Shader shader;


public:

	Shape();
	void Draw(IndexBuffer ib);
};


