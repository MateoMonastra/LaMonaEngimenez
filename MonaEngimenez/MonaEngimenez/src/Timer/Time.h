#pragma once
#include "Exporter.h"

static class MONA_ENGIMENEZ Time
{

public:
	static double oldTime;
	static float timeSinceStart;
	static float currentTime;

	static float getDeltaTime();
	static void setTime();
	static float getTime();
};

