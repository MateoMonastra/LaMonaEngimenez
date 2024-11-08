#include "Animation.h"

Animation::Animation(Sprite* sprite, glm::ivec2 frameCount, int row)
{
	this->sprite = sprite;
	m_FrameCount = frameCount;
	m_CurrentFrame = 0;

	m_FrameSize = glm::vec2(sprite->GetWidth() / frameCount.x, sprite->GetHeight() / frameCount.y);

	m_Frames = new Frame[m_FrameCount.x];

	SetFrames(row);
}

Animation::Animation(Sprite* sprite, glm::ivec2 m_FrameCount)
{
	Animation(sprite, m_FrameCount, 0);
}

Animation::~Animation()
{
	delete[] m_Frames;
}

void Animation::SetFrames(int row)
{
	for (int i = 0; i < m_FrameCount.x; i++)
	{
		float u = (i * m_FrameSize.x) / sprite->GetWidth();
		float v = (row * m_FrameSize.y) / sprite->GetHeight();

		float u_end = u + m_FrameSize.x / sprite->GetWidth();
		float v_end = v + m_FrameSize.y / sprite->GetHeight();

		m_Frames[i].uv[0] = { u, v };
		m_Frames[i].uv[1] = { u_end, v };
		m_Frames[i].uv[2] = { u_end, v_end };
		m_Frames[i].uv[3] = { u, v_end };
	}
}

void Animation::DrawAnimation(int frameIndex)
{
	if (m_CurrentFrame >= 0 && m_CurrentFrame < m_FrameCount.x)
	{
		m_CurrentFrame = frameIndex;

		const Frame& frame = m_Frames[m_CurrentFrame];

		float positions[] = 
		{
			-0.5f, -0.5f,     frame.uv[0].u, frame.uv[0].v,
			 0.5f, -0.5f,     frame.uv[1].u, frame.uv[1].v,
			 0.5f,  0.5f,     frame.uv[2].u, frame.uv[2].v,
			-0.5f,  0.5f,     frame.uv[3].u, frame.uv[3].v
		};

		sprite->GetVertexBuffer().SetVertexBuffer(positions, sizeof(positions));

		sprite->Draw(1.0f);
	}
}
