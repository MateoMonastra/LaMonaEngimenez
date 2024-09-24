#pragma once
#include "Exporter.h"

#include "Entity/Entity2D/Shape/Shape.h"
#include "BufferLayout/BufferLayout.h"



class Square : public Shape
{
public:

	Square(BufferLayout layout, float width, float height);
	~Square();
};

