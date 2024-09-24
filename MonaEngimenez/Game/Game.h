#pragma once

#include "BaseGame.h"
#include <Entity/Entity2D/Shape/Square/Square.h>


class Game : public BaseGame
{
private:

	Square* square;

public:

	Game(float width, float height);
	~Game() override;

	void Init() override;
	void Update() override;
	void Deinit() override;
};
