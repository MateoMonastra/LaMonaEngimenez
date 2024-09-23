#pragma once
#include "Exporter.h"

#include "Entity/Entity.h"


MONA_ENGIMENEZ class Entity2D : public Entity
{
public:
	virtual void Draw(IndexBuffer ib) = 0;
};