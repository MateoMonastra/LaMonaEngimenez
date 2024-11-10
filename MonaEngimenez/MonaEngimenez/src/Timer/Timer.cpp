#include "Timer.h"

std::chrono::time_point<std::chrono::high_resolution_clock> DeltaTime::lastFrameTime;
float DeltaTime::deltaTime = 0.0f;

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

void DeltaTime::Init()
{
	deltaTime = 0.0f;
	lastFrameTime = std::chrono::steady_clock::now();
}

void DeltaTime::Update()
{
	auto currentFrameTime = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> elapsed = currentFrameTime - lastFrameTime;

	deltaTime = elapsed.count();

	lastFrameTime = currentFrameTime;
}

float DeltaTime::GetDeltaTime()
{
	return deltaTime;
}
