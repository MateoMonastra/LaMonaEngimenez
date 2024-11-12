#pragma once

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Entity2D.h"
#include "Animation/Animation.h"

class MONA_ENGIMENEZ Sprite : public Entity2D
{
private:
	Animation* animation;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	float positions[16];
	bool isAnimated = false;

public:
	Sprite(const std::string& path);
	Sprite(const std::string& path, glm::ivec2 frameCount);
	Sprite(const std::string& path, glm::ivec2 frameCount, int row);
	~Sprite();

	void Draw(float alpha);
	void Draw() override;
	void Animate();
	void UpdateVertexBuffer();
	void SetFullTexture();

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};