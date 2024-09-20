#pragma once

#include "Exporter.h"
#include <glew.h>
#include "Window/Window.h"



MONA_ENGIMENEZ class BaseGame
{
public:
	MONA_ENGIMENEZ BaseGame();
	MONA_ENGIMENEZ ~BaseGame();

	MONA_ENGIMENEZ int TryTest();
	MONA_ENGIMENEZ void Update(Window& window);
};