#pragma once

#include "Exporter.h"

#include "IndexBuffer/IndexBuffer.h"

MONA_ENGIMENEZ class Entity
{
public:
	 virtual void Draw(IndexBuffer ib) = 0;
};

