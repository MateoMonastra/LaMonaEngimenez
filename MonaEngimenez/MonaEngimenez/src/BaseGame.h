#pragma once

#include "Exporter.h"

class Window;

class MONA_ENGIMENEZ BaseGame
{
protected:

	Window* window;

public:

	BaseGame();
	BaseGame(float width, float height);
	virtual ~BaseGame();

	void GameLoop();
	virtual void Init() = 0;
	virtual void Update() = 0;
	inline virtual void Deinit() {};
};