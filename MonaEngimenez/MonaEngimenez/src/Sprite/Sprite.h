#pragma once

#include "Renderer/Renderer.h"
#include "Entity/Entity2D/Entity2D.h"

class MONA_ENGIMENEZ Sprite : public Entity2D
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	float m_Alpha;

public:
	Sprite(const std::string& path);
	~Sprite();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	void Draw(float alpha);
	void Draw() override;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline void SetAlpha(float alpha);
	inline VertexBuffer GetVertexBuffer();
	inline IndexBuffer GetIndexBuffer();
	inline VertexArray GetVertexArray();
	inline Shader GetShader();
};