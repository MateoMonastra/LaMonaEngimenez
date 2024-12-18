#pragma once

#include "Exporter.h"
#include "glew.h"
#include "InputManager/InputManager.h"

class Window;

class MONA_ENGIMENEZ BaseGame
{
protected:

	Window* window;
	InputManager* inputManager;
	float screenWidth;
	float screenHeight;
	float screenCenterX;
	float screenCenterY;

public:

	BaseGame();
	BaseGame(float width, float height);
	virtual ~BaseGame();

	void GameLoop();
	virtual void Init() = 0;
	virtual void Update() = 0;
	inline virtual void Deinit() {};
};