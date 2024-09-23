#pragma once
#include "Exporter.h"

#include "Entity/Entity.h"


MONA_ENGIMENEZ class Entity2D : public Entity
{
public:

	Entity2D(Renderer* renderer, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation);
	~Entity2D();

	MONA_ENGIMENEZ virtual void Draw() = 0;
private:
};