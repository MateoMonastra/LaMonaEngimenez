#pragma once

#include "BaseGame.h"
#include <Entity/Entity2D/Shape/Triangle/Triangle.h>
#include <Entity/Entity2D/Shape/Square/Square.h>
#include "Sprite/Sprite.h"
#include "Animation/Animation.h"
#include "Timer/Time.h"


class Game : public BaseGame
{
private:

	Sprite* knuckles;
	Animation* knucklesIdle;
	Animation* knucklesWalking;
	Animation* knucklesSpin;

	bool isMoving = false;


public:

	Game(float width, float height);
	~Game() override;

	void Init() override;
	void Update() override;
	void Deinit() override;

	void GetInput();
	void Draw();
};
