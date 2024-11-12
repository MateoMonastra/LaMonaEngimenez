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
	knuckles->SetTranslation(50.0f, 50.0f);

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

	int spinWidth = 33;
	int spinHeight = 29;
	int spinTotalFrames = 11;
	float spinScaleX = 1.0f / knuckles->GetWidth() * spinWidth;
	float spinScaleY = 1.0f / knuckles->GetHeight() * spinHeight;
	intialY = knuckles->GetHeight() - 159;
	knucklesSpin = new Animation(0, intialY, spinTotalFrames, 1.5f, knuckles->GetWidth(), knuckles->GetHeight(), spinWidth, spinHeight);
	//knuckles->SetAnimation(knucklesSpin);

	int deathWidth = 33;
	int deathHeight = 35;
	int deathTotalFrames = 4;
	float deathScaleX = 1.0f / knuckles->GetWidth() * deathWidth;
	float deathScaleY = 1.0f / knuckles->GetHeight() * deathHeight;
	intialY = knuckles->GetHeight() - 131;
	knucklesPush = new Animation(427, intialY, deathTotalFrames, 0.5f, knuckles->GetWidth(), knuckles->GetHeight(), deathWidth, deathHeight);
	//knuckles->SetAnimation(knucklesDeath);




	rock = new Sprite("../Assets/Rock.jfif");
	rock->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	rock->SetTranslation(500.0f, 500.0f);

	int rockWidth = 81;
	int rockHeight = 56;
	int rockTotalFrames = 1;
	float rockScaleX = 1.0f / rock->GetWidth() * rockWidth;
	float rockScaleY = 1.0f / rock->GetHeight() * rockHeight;
	int initialX = 77;
	intialY = rock->GetHeight() - 77;

	rockIdle = new Animation(initialX, intialY, rockTotalFrames, 0.1f, rock->GetWidth(), rock->GetHeight(), rockWidth, rockHeight);
	rock->SetAnimation(rockIdle);


}

void Game::Update()
{
	GetInput();

	CheckCollisions();

	Draw();
}

void Game::Deinit()
{
	delete knuckles;
	delete knucklesIdle;
	delete knucklesWalking;
	delete knucklesSpin;
	delete knucklesPush;

	delete rock;
	delete rockIdle;
}

void Game::GetInput()
{
	glm::vec2 velocity{ 0.0f, 0.0f };
	float rotation = 0.0f;
	glm::vec2 scale{ 0.0f, 0.0f };
	float alpha = 0.0f;
	isMoving = false;
	isSpining = false;

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
	if (inputManager->GetKey(space, Pressed))
	{
		isSpining = true;
	}

	knuckles->UpdateTransform(velocity, rotation, scale);
	knuckles->UpdateAlpha(alpha);

	if (isSpining)
	{
		knuckles->SetAnimation(knucklesSpin);
		//knuckles->SetAnimation(knucklesPush);
	}
	else if (isMoving)
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
	rock->Animate();
	knuckles->Animate();
}

void Game::CheckCollisions()
{
	if (CollisionManager::CheckCollisionRecRec(knuckles, rock))
	{
		knuckles->SetAnimation(knucklesPush);
		std::cout << "Colliding" << std::endl;	
	}
}
