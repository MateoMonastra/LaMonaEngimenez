#pragma once
#include "Entity/Entity2D/Entity2D.h"
#include "BufferDirection/BufferDirection.h"


	static const int SHAPE_VERTEX_COUNT = 9;

	class Shape : Entity2D
	{
	public:
		float vertices[SHAPE_VERTEX_COUNT];
		BufferDirection bufferDirection;

		Shape(float vertices[]);

		void Draw();
	};


