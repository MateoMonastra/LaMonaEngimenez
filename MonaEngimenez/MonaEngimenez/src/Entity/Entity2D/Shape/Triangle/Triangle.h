#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Shape/Shape.h"


MONA_ENGIMENEZ class Triangle : public Shape
{
public:
	Triangle(Renderer* renderer, glm::vec3 position, glm::vec3 scale);
	~Triangle();
};

