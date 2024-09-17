#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Entity2D.h"
//#include "BufferDirection/BufferDirection.h"



static const int SHAPE_VERTEX_COUNT = 9;

MONA_ENGIMENEZ class Shape : Entity2D
{
public:
	float vertices[SHAPE_VERTEX_COUNT];
	//BufferDirection bufferDirection;

	MONA_ENGIMENEZ Shape(float vertices[]);

	MONA_ENGIMENEZ void Draw();
};


