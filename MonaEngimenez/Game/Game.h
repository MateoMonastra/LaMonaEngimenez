#pragma once

#include "BaseGame.h"
#include "Sprite/Sprite.h"
#include "Animation/Animation.h"
#include "Timer/Time.h"
#include "CollisionManager/CollisionManager.h"


class Game : public BaseGame
{
private:

	Sprite* knuckles;
	Sprite* rock;
	Sprite* GreenHill;
	Animation* knucklesIdleAnimation;
	Animation* knucklesRunningRightAnimation;
	Animation* knucklesSpinAttackAnimation;
	Animation* knucklesPushAnimation;
	Animation* rockIdle;
	

public:

	Game(float width, float height);
	~Game() override;

	void Init() override;
	void Update() override;
	void Deinit() override;

	void GetInput();
	void KnucklesColition();
	void Draw();
};
