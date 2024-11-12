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
	knuckles = new Sprite("../Assets/Knuckles.png");


	knuckles->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	knuckles->SetTranslation(500.0f, 500.0f);
	//knucklesIdle = new Animation(0, 0, 1, 0.1f, knuckles->GetWidth(), knuckles->GetHeight(), 34, 39);

	///knuckles
	// Idle
	int idleWidth = 32;
	int idleHeight = 39;
	int idleTotalFrames = 1;
	float idleScaleX = 1.0f / knuckles->GetWidth() * idleWidth;
	float idleScaleY = 1.0f / knuckles->GetHeight() * idleHeight;
	int intialY = knuckles->GetHeight() - idleHeight;

	knuckles->SetScale(glm::vec3(idleScaleX * 2, idleScaleY * 2, 0.0f));

	knucklesIdle = new Animation(0, intialY, idleTotalFrames, 0.1f, knuckles->GetWidth(), knuckles->GetHeight(), idleWidth, idleHeight);
	knuckles->SetAnimation(knucklesIdle);

	int walkingWidth = 38;
	int walkingHeight = 40;
	int walkingTotalFrames = 4;
	float walkingScaleX = 1.0f / knuckles->GetWidth() * walkingWidth;
	float walkingScaleY = 1.0f / knuckles->GetHeight() * walkingHeight;
	intialY = knuckles->GetHeight() - 85;
	knucklesWalking = new Animation(338, intialY, walkingTotalFrames, 0.4f, knuckles->GetWidth(), knuckles->GetHeight(), walkingWidth, walkingHeight);
}

void Game::Update()
{
	GetInput();

	Draw();
}

void Game::Deinit()
{
	delete knuckles;
	delete knucklesIdle;
	delete knucklesWalking;
	delete knucklesSpin;

}

void Game::GetInput()
{
	glm::vec2 velocity{ 0.0f, 0.0f };
	float rotation = 0.0f;
	glm::vec2 scale{ 0.0f, 0.0f };
	float alpha = 0.0f;
	isMoving = false;

	if (inputManager->GetKey(w, Pressed))
	{
		velocity.y = 1.0f * Time::getDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(s, Pressed))
	{
		velocity.y = -1.0f * Time::getDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(d, Pressed))
	{
		velocity.x = 1.0f * Time::getDeltaTime();
		isMoving = true;
		scale.x = abs(scale.x);
	}
	if (inputManager->GetKey(a, Pressed))
	{
		velocity.x = -1.0f * Time::getDeltaTime();
		isMoving = true;
		//scale.x = abs(scale.x * -1.0f);
		scale.x = scale.x  * -1.0f;
	}
	if (inputManager->GetKey(q, Pressed))
	{
		rotation = 1.0f * Time::getDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(e, Pressed))
	{
		rotation = -1.0f * Time::getDeltaTime();
		isMoving = true;
	}
	if (inputManager->GetKey(add, Pressed))
	{
		scale.x = 1.0f * Time::getDeltaTime();
		scale.y = 1.0f * Time::getDeltaTime();
	}
	if (inputManager->GetKey(subtract, Pressed))
	{
		scale.x = -1.0f * Time::getDeltaTime();
		scale.y = -1.0f * Time::getDeltaTime();
	}
	if (inputManager->GetKey(r, Pressed))
	{
		alpha = 1.0f * Time::getDeltaTime();
	}
	if (inputManager->GetKey(t, Pressed))
	{
		alpha = -1.0f * Time::getDeltaTime();
	}

	knuckles->UpdateTransform(velocity, rotation, scale);
	knuckles->UpdateAlpha(alpha);

	if (isMoving)
	{
		knuckles->SetAnimation(knucklesWalking);
	}
	else
	{
		knuckles->SetAnimation(knucklesIdle);
	}
}

void Game::Draw()
{
	//burst->Animate();
	//milhouse->Draw();
	//triangle->Draw();


	knuckles->Animate();

}
