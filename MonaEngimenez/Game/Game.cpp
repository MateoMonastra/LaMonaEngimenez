#pragma once

#include "Game.h"  
#include "Window\Window.h"
#include "glm.hpp"


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
   milhouse = new Sprite("../Assets/Milhouse.png", glm::ivec2(1, 1), 0);
   dynoBoy = new Sprite("../Assets/Player.png", glm::ivec2(3, 1), 0);
   triangle = new Triangle(400.0f,400.0f);
   //burst = new Sprite("../Assets/Burst.png", glm::ivec2(3, 1), 0);

   dynoBoy->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
   dynoBoy->SetTranslation(500.0f, 500.0f);

   //burst->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
   //burst->SetTranslation(500.0f, 500.0f);

   milhouse->SetScale(glm::vec3(0.1f, 0.1f, 0.0f));
   milhouse->SetTranslation(milhouse->GetWidth() / 2.0f, milhouse->GetHeight() / 2.0f);
}  

void Game::Update()  
{  
	GetInput();

	Draw();
}  

void Game::Deinit()  
{  
	delete dynoBoy;
	//delete burst;
	delete milhouse;
}

void Game::GetInput()
{
	glm::vec2 velocity{0.0f, 0.0f};
	float rotation = 0.0f;
	glm::vec2 scale{ 0.0f, 0.0f };
	float alpha = 0.0f;
	isMoving = false;

	if (inputManager->GetKey(w, Pressed))
	{
		velocity.y = 1.0f * DeltaTime::GetDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(s, Pressed))
	{
		velocity.y = -1.0f * DeltaTime::GetDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(d, Pressed))
	{
		velocity.x = 1.0f * DeltaTime::GetDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(a, Pressed))
	{
		velocity.x = -1.0f * DeltaTime::GetDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(q, Pressed))
	{
		rotation = 1.0f * DeltaTime::GetDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(e, Pressed))
	{
		rotation = -1.0f * DeltaTime::GetDeltaTime();
		isMoving = true;
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
	if (inputManager->GetKey(r, Pressed))
	{
		alpha = 1.0f * DeltaTime::GetDeltaTime();
	}
	if (inputManager->GetKey(t, Pressed))
	{
		alpha = -1.0f * DeltaTime::GetDeltaTime();
	}

	dynoBoy->UpdateTransform(velocity, rotation, scale);
	dynoBoy->UpdateAlpha(alpha);
}

void Game::Draw()
{
	//burst->Animate();
	milhouse->Draw();
	triangle->Draw();

	if (isMoving)
	{
		dynoBoy->Animate();
	}
	else
	{
		dynoBoy->Draw();
	}
}

