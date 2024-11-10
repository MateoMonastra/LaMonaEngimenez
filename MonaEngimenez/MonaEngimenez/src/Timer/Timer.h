#pragma once

#include <chrono>

class Timer
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

