#pragma once

#include "Sprite/Sprite.h"
#include "Frame/Frame.h"

class MONA_ENGIMENEZ Animation
{
private:

	Sprite* sprite;
	glm::vec2 m_FrameSize;
	glm::ivec2 m_FrameCount;
	int m_CurrentFrame;
	Frame* m_Frames;


public:

	Animation(Sprite* sprite, glm::ivec2 m_FrameCount, int row);
	Animation(Sprite* sprite, glm::ivec2 m_FrameCount);
	~Animation();

	void SetFrames(int row);
	void DrawAnimation(int frameIndex);
};

