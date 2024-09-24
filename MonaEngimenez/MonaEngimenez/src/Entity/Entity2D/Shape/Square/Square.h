#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Shape/Shape.h"
#include "BufferLayout/BufferLayout.h"



class MONA_ENGIMENEZ Square : public Shape
{
public:

	Square(float width, float height);
	~Square();
};

