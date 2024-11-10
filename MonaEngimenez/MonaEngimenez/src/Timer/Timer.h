#pragma once
#include "Exporter.h"

#include <chrono>

class MONA_ENGIMENEZ Timer
{
private:

	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
	float m_Duration;


public:
	Timer(float duration);
	~Timer();

	void Reset();
	bool HasElapsed();
	float TimeRemaining();
};

static class MONA_ENGIMENEZ DeltaTime
{
protected:
	static std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime;
	static float deltaTime;

public:
	static void Init();
	static void Update();
	static float GetDeltaTime();
};

