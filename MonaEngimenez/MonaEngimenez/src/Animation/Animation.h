#pragma once

#include "glm.hpp"

#include "Exporter.h"
#include "Frame/Frame.h"

class MONA_ENGIMENEZ Animation
{
private:

	Frame* m_Frames;
	glm::vec2 m_FrameSize;
	glm::ivec2 m_FrameCount;
	glm::ivec2 m_ScaleFactor;
	int m_CurrentFrame;

public:

	Animation(glm::ivec2 frameCount, glm::ivec2 spriteSize, glm::ivec2 scaleFactor, int row);
	Animation(glm::ivec2 frameCount, glm::ivec2 spriteSize, glm::ivec2 scaleFactor);
	~Animation();

	void SetFrames(glm::ivec2 spriteSize, int row);
	void GetFrame(float positions[]);
	float GetFrameWidth();
	float GetFrameHeight();
	glm::vec2 GetFrameSize();
	glm::vec2 GetScaleFactor();
	void Unload();
};

