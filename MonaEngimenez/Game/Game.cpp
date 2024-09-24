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
   square = new Square(100.0f, 100.0f);

   square->SetTranslation(square->GetWidth() / 2.0f, (screenHeight / 2.0f));
   square->SetColor(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
}  

void Game::Update()  
{  
	square->Translate(0.5f, 0.0f);
	square->Scale(glm::vec3(-0.2f, -0.2f, 0.0f));
	square->Rotate(-0.01f);

	square->Draw();
}  

void Game::Deinit()  
{  
	delete square;
}
