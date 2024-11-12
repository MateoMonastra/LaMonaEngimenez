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
	knuckles = new Sprite("../Assets/Knuckles_Sprite_Sheet.png");
	rock = new Sprite("../Assets/Rock.png");
	GreenHill = new Sprite("../Assets/GreenHill.png");

	knuckles->SetScale(glm::vec3(0.3f, 0.3f, 0.0f));
	knuckles->SetRotation(180.0f);
	knuckles->SetTranslation(500.0f, 200.0f);

	knucklesIdleAnimation = new Animation(0, 473, 1, 3, 646, 473, 36, -40);
	knucklesRunningRightAnimation = new Animation(377, 473 - 46, 2, 3, 646, 473, 40, -40);
	knucklesSpinAttackAnimation = new Animation(0, 473 - 128, 6, 3, 646, 473, 32, -33);
	knucklesPushAnimation = new Animation(429, 473 - 97, 4, 3, 646, 473, 33, -34);

	knuckles->SetAnimation(knucklesIdleAnimation);

	rock->SetScale(glm::vec3(0.8f, 0.8f, 0.0f));
	rock->SetRotation(180.0f);
	rock->SetTranslation(200.0f, 200.0f);
	rockIdle = new Animation(65, 244 -24, 1, 2, 207, 244, 67, -68);

	rock->SetAnimation(rockIdle);

	GreenHill->SetScale(glm::vec3(4.0f, 5.0f, 0.0f));
	GreenHill->SetTranslation(500.0f, 350.0f);
}
void Game::Update()
{
	GetInput();
	KnucklesColition();
	Draw();
}

void Game::Deinit()
{
	delete knuckles;
	delete GreenHill;
	delete knucklesIdleAnimation;
	delete knucklesRunningRightAnimation;
	delete knucklesSpinAttackAnimation;
	delete knucklesPushAnimation;
	delete rockIdle;
	delete rock;
}

void Game::GetInput()
{
	glm::vec2 velocity{ 0.0f, 0.0f };
	float rotation = 0.0f;
	glm::vec2 scale{ 0.0f, 0.0f };

	if (inputManager->GetKey(w, Pressed))
	{
		velocity.y = 2.0f * Time::getDeltaTime();
		knuckles->ChangeAnimation(knucklesRunningRightAnimation);
	}

	if (inputManager->GetKey(a, Pressed))
	{
		velocity.x = -2.0f * Time::getDeltaTime();
		knuckles->ChangeAnimation(knucklesRunningRightAnimation);
	}
	else if (inputManager->GetKey(d, Pressed))
	{
		velocity.x = 2.0f * Time::getDeltaTime();
		knuckles->ChangeAnimation(knucklesRunningRightAnimation);
	}
	else if (inputManager->GetKey(s, Pressed))
	{
		velocity.y = -2.0f * Time::getDeltaTime();
		knuckles->ChangeAnimation(knucklesRunningRightAnimation);
	}
	else if (inputManager->GetKey(p, Pressed))
	{
		knuckles->ChangeAnimation(knucklesSpinAttackAnimation);
	}
	else
	{
		knuckles->ChangeAnimation(knucklesIdleAnimation);
	}

	knuckles->UpdateTransform(velocity, rotation, scale);
}

void Game::KnucklesColition()
{
	if (CollisionManager::CheckCollisionRecRec(knuckles,rock))
	{
		
		knuckles->SetAnimation(knucklesPushAnimation);
	}
}

void Game::Draw()
{
	GreenHill->Draw();
	knuckles->Animate();
	rock->Animate();
}


