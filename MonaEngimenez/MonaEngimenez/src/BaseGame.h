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
	~BaseGame();

	void GameLoop();
	virtual void Init();
	virtual void Update();
	virtual void Deinit();
};