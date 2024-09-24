#include "Game.h"


int main()
{
	Game* game = new Game(1024.0f, 720.0f);

	game->GameLoop();

	delete game;

	return 1;
}