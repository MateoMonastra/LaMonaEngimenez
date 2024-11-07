#pragma once

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Entity2D.h"

class MONA_ENGIMENEZ Texture : public Entity2D
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;

public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	void Draw() override;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};