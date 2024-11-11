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
	glm::vec2 velocity{0.0f, 0.0f};
	float rotation = 0.0f;
	glm::vec2 scale{ 0.0f, 0.0f };

	if (inputManager->GetKey(w, Pressed))
	{
		velocity.y = 1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(s, Pressed))
	{
		velocity.y = -1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(d, Pressed))
	{
		velocity.x = 1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(a, Pressed))
	{
		velocity.x = -1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(q, Pressed))
	{
		rotation = 1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(e, Pressed))
	{
		rotation = -1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(add, Pressed))
	{
		scale.x = 1.0f * DeltaTime::GetDeltaTime();
		scale.y = 1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(subtract, Pressed))
	{
		scale.x = -1.0f * DeltaTime::GetDeltaTime();
		scale.y = -1.0f * DeltaTime::GetDeltaTime();
	}

	sprite->UpdateTransform(velocity, rotation, scale);
}

