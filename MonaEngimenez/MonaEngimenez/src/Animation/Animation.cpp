#include "Animation.h"

Animation::Animation(glm::ivec2 frameCount, glm::ivec2 spriteSize, glm::ivec2 scaleFactor, int row)
{
	m_FrameCount = frameCount;
	m_CurrentFrame = 0;

	m_FrameSize = glm::vec2(spriteSize.x / frameCount.x, spriteSize.y / frameCount.y);

	m_Frames = new Frame[m_FrameCount.x];

	m_ScaleFactor = scaleFactor / frameCount;

	SetFrames(spriteSize, row);

	m_Timer = new Timer(0.3f);
}

Animation::Animation(glm::ivec2 frameCount, glm::ivec2 spriteSize, glm::ivec2 scaleFactor)
{
	Animation(frameCount, spriteSize, scaleFactor, 0); //chequear si es row 0 o row 1
}

Animation::~Animation()
{
}

void Animation::Update()
{
	if (m_Timer->HasElapsed())
	{
		m_CurrentFrame += 1;

		m_Timer->Reset();

		if (m_CurrentFrame + 1 > m_FrameCount.x)
		{
			m_CurrentFrame = 0;
		}
	}
}

void Animation::SetFrames(glm::ivec2 spriteSize, int row)
{
	for (int i = 0; i < m_FrameCount.x; i++)
	{
		float u = (i * m_FrameSize.x) / spriteSize.x;
		float v = (row * m_FrameSize.y) / spriteSize.y;

		float u_end = u + m_FrameSize.x / spriteSize.x;
		float v_end = v + m_FrameSize.y / spriteSize.y;

		m_Frames[i].uv[0] = { u, v };
		m_Frames[i].uv[1] = { u_end, v };
		m_Frames[i].uv[2] = { u_end, v_end };
		m_Frames[i].uv[3] = { u, v_end };
	}
}

void Animation::GetFrame(float positions[])
{
	Update();

	if (m_CurrentFrame >= 0 && m_CurrentFrame < m_FrameCount.x)
	{
		positions[2] = m_Frames[m_CurrentFrame].uv[0].u;
		positions[3] = m_Frames[m_CurrentFrame].uv[0].v;
		positions[6] = m_Frames[m_CurrentFrame].uv[1].u;
		positions[7] = m_Frames[m_CurrentFrame].uv[1].v;
		positions[10] = m_Frames[m_CurrentFrame].uv[2].u;
		positions[11] = m_Frames[m_CurrentFrame].uv[2].v;
		positions[14] = m_Frames[m_CurrentFrame].uv[3].u;
		positions[15] = m_Frames[m_CurrentFrame].uv[3].v;
	}
}

float Animation::GetFrameWidth()
{
	return m_FrameSize.x;
}

float Animation::GetFrameHeight()
{
	return m_FrameSize.y;
}

glm::vec2 Animation::GetFrameSize()
{
	return m_FrameSize;
}

glm::vec2 Animation::GetScaleFactor()
{
	return m_ScaleFactor;
}

void Animation::Unload()
{
	delete m_Timer;
	delete[] m_Frames;
}
