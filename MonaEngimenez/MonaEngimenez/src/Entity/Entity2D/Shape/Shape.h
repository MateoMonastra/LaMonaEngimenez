#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Entity2D.h"


MONA_ENGIMENEZ class Shape : public Entity2D
{
public:

	MONA_ENGIMENEZ Shape(Renderer* renderer, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation);

	MONA_ENGIMENEZ void Draw();
};


