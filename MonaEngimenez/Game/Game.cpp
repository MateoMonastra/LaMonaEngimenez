#pragma once

#include "Game.h"  
#include "Window\Window.h"
#include "glm.hpp"


static float FlashingColor()
{
	static float increment = 0.005f;
	static float color = 0.0f;

	if (color > 1.0f || color < 0.0f)
	{
		increment = -increment;
	}

	return color += increment;
}

Game::Game(float width, float height)
	: BaseGame(width, height)
{
	Init();
}

Game::~Game()
{
	Deinit();
}

void Game::Init()
{  
   sprite = new Sprite("../Assets/Player.png");
   animation = new Animation(sprite, glm::ivec2(3, 1), 0);
}  

void Game::Update()  
{  
	sprite->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	sprite->SetTranslation(sprite->GetWidth() / 2.0f, sprite->GetHeight() / 2.0f);
	//sprite->Draw(1.0f);

	animation->DrawAnimation(1);
}  

void Game::Deinit()  
{  
	delete sprite;
	delete animation;
}
