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
   texture = new Texture("../Assets/Player.png", 3, 1);

   //texture->SetTranslation(texture->GetWidth() / 2.0f, (screenHeight - texture->GetHeight() / 2.0f));
   //texture->SetScale(glm::vec3(0.5f, 0.5f, 0.0f));
   
}  

void Game::Update()  
{  
	texture->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	texture->SetTranslation(texture->GetWidth() / (6.0f), (screenHeight - texture->GetHeight() / 2.0f));
	//texture->SetTranslation(0, 0);
	texture->Draw(1.0f);
}  

void Game::Deinit()  
{  
	delete texture;
}
