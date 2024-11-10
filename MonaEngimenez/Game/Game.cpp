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
   sprite = new Sprite("../Assets/Player.png", glm::ivec2(3, 1), 0);
   sprite->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
   sprite->SetTranslation(500.0f, 500.0f);
   //animation = new Animation(sprite, glm::ivec2(3, 1), 0);
   //triangle = new Triangle(200.0f, 200.0f);
}  

void Game::Update()  
{  
	//triangle->SetTranslation(500.0f, 500.0f);
	//triangle->SetRotation(180.0f);
	//triangle->Draw();
	
	GetInput();

	sprite->Draw(1.0f);
}  

void Game::Deinit()  
{  
	delete sprite;
	//delete triangle;
}

void Game::GetInput()
{
	glm::ivec2 direction(0, 0);
	
	if (inputManager->GetKey(w, Pressed) || inputManager->GetKey(w, Released))
	{
		direction.y = 1;
	}
	if (inputManager->GetKey(s, Pressed) || inputManager->GetKey(s, Released))
	{
		direction.y = -1;
	}
	if (inputManager->GetKey(d, Pressed) || inputManager->GetKey(d, Released))
	{
		direction.x = 1;
	}
	if (inputManager->GetKey(a, Pressed) || inputManager->GetKey(a, Released))
	{
		direction.x = -1;
	}

	sprite->Move(direction);

	if (inputManager->GetKey(q, Pressed) || inputManager->GetKey(q, Released))
	{
		sprite->Rotate(-0.1f);
	}
	if (inputManager->GetKey(e, Pressed) || inputManager->GetKey(e, Released))
	{
		sprite->Rotate(0.1f);
	}

	if (inputManager->GetKey(add, Pressed) || inputManager->GetKey(add, Released))
	{
		sprite->Scale(glm::vec3(0.1f, 0.1f, 0.0f));
	}
	if (inputManager->GetKey(subtract, Pressed) || inputManager->GetKey(subtract, Released))
	{
		sprite->Scale(glm::vec3(-0.1f, -0.1f, 0.0f));
	}
}

