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
   square = new Square(300.0f, 300.0f);  

   square->SetTranslation(window->GetWidth() / 4.0f, window->GetHeight() / 2.0f);
   square->SetColor(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
}  

void Game::Update()  
{  
	square->Rotate(-0.001f);
	square->Translate(0.5f, 0.0f);
	square->Scale(glm::vec3(-0.15f, -0.15f, 0.0f));

	square->Draw();
}  

void Game::Deinit()  
{  
	delete square;
}
