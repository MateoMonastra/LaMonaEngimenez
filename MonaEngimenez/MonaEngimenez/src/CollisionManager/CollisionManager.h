#pragma once
#include "Exporter.h"
#include "Entity/Entity2D/Entity2D.h"


	class MONA_ENGIMENEZ CollisionManager : public Entity2D
	{
	public:

		static bool CheckCollisionRecRec(Entity2D* entityOne, Entity2D* entityTwo);
	};