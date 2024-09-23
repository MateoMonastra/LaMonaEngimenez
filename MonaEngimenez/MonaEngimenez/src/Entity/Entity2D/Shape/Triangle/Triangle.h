#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Shape/Shape.h"
#include "BufferLayout/BufferLayout.h"


class Triangle : public Shape
{	

public:

	Triangle(BufferLayout layout, float width, float height);
	~Triangle();

	void Move();
};

