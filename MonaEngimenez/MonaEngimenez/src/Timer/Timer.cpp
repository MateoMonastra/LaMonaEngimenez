#include "Timer.h"

Timer::Timer(float duration)
{
	m_Duration = duration;
	m_StartTime = std::chrono::steady_clock::now();
}

Timer::~Timer()
{
}

void Timer::Reset()
{
	m_StartTime = std::chrono::steady_clock::now();
}

bool Timer::HasElapsed()
{
	auto currentTime = std::chrono::steady_clock::now();

	std::chrono::duration<float> elapsed = currentTime - m_StartTime;

	return elapsed.count() >= m_Duration;
}

float Timer::TimeRemaining()
{
	return 0.0f;
}
