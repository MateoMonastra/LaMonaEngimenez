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
   //triangle1 = new Triangle(300.0f, 300.0f);  
   texture = new Texture("../Assets/Milhouse.png");
   //triangle2 = new Triangle(300.0f, 300.0f);  
   //square = new Square(300.0f, 300.0f);  

   texture->SetTranslation(texture->GetWidth() / 2.0f, (screenHeight - texture->GetHeight() / 2.0f));
   //texture->SetColor(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));


  // square->SetTranslation(window->GetWidth() / 2.0f, window->GetHeight() / 2.0f);
}  

void Game::Update()  
{  
	//triangle1->Rotate(-0.001f);
	//triangle1->Translate(0.1f, 0.1f);
	//triangle1->SetColor(glm::vec4(FlashingColor(), 0.7f, 0.2f, 1.0f));

	//square->Rotate(0.001f);
	//square->Scale(glm::vec3(0.1f, -0.2f, 0.0f));
	//square->SetColor(glm::vec4(FlashingColor(), 0.0f, FlashingColor(), 1.0f));
	//texture->SetAlpha(0.5f);

	texture->Draw(0.1f);
	//square->Draw();
}  

void Game::Deinit()  
{  
	delete texture;
	//delete triangle2;
	//delete square;
}
