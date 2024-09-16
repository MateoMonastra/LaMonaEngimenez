#pragma once
#include "Exporter.h"
#include <glew.h>

#include "Entity/Entity2D/Entity2D.h"



static const int SHAPE_VERTEX_COUNT = 9;

MONA_ENGIMENEZ class Shape : Entity2D
{
public:
	float vertices[SHAPE_VERTEX_COUNT];

	MONA_ENGIMENEZ Shape(float vertices[]);

	MONA_ENGIMENEZ void Draw();
};


