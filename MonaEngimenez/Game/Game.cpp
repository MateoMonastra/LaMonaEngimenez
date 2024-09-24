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
   triangle = new Triangle(300.0f, 300.0f);  
   square = new Square(300.0f, 300.0f);  

   square->SetTranslation(window->GetWidth() / 2.0f, window->GetHeight() / 2.0f);
}  

void Game::Update()  
{  
	triangle->Rotate(-0.001f);
	triangle->Translate(0.1f, 0.1f);
	triangle->SetColor(glm::vec4(FlashingColor(), 0.7f, 0.2f, 1.0f));

	square->Rotate(0.001f);
	square->Scale(glm::vec3(0.1f, -0.2f, 0.0f));
	square->SetColor(glm::vec4(FlashingColor(), 0.0f, FlashingColor(), 1.0f));

	triangle->Draw();
	square->Draw();
}  

void Game::Deinit()  
{  
	delete triangle;
	delete square;
}
