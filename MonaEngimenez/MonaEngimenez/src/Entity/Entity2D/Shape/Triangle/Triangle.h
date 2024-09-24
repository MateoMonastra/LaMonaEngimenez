#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Shape/Shape.h"
#include "BufferLayout/BufferLayout.h"


class Triangle : public Shape
{
private:

public:

	Triangle(BufferLayout layout, float width, float height);
	~Triangle();

	//void Move(float x, float y);
	//void Rotate(float angle);
	//void Scale(glm::vec3 scale);
};

