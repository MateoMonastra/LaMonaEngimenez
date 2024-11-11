#include "Sprite.h"

#include "Debugger/Debugger.h"

Sprite::Sprite(const std::string& path)
	: m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)

{
	unsigned int indices[]
	{
		0,1,2,
		2,3,0
	};

	SetFullTexture();

	SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	SetRotation(0.0f);
	SetTranslation(0.0f, 0.0f);


	shader.SetShader("../Resources/Texture.shader");
	
	layout.Push<float>(2);
	layout.Push<float>(2);

	ib = new IndexBuffer(indices, 6);

	vb.SetVertexBuffer(positions, 4 * 4 * sizeof(float));
	va.AddBuffer(vb, layout);

	Renderer::LoadImage(path, m_RendererID, m_Width, m_Height, m_BPP, m_LocalBuffer);

	shader.SetUniform1i("u_Texture", 0);

	scaleFactorX = m_Width;
	scaleFactorY = m_Height;

	vb.Unbind();
	va.Unbind();
	ib->Unbind();
}

Sprite::Sprite(const std::string& path, glm::ivec2 frameCount)
{
	Sprite(path, frameCount, 0);
}

Sprite::Sprite(const std::string& path, glm::ivec2 frameCount, int row)
	: Sprite(path)
{
	isAnimated = true;
	animation = new Animation(frameCount, glm::ivec2(m_Width, m_Height), glm::ivec2(scaleFactorX, scaleFactorY), row);
	scaleFactorX = m_Width / frameCount.x;
	scaleFactorY = m_Height / frameCount.y;
}

Sprite::~Sprite()
{
	DebuggerCall(glDeleteTextures(1, &m_RendererID));

	if (isAnimated)
	{
		animation->Unload();
		delete animation;
	}
}

void Sprite::Draw(float alpha)
{
	animation->GetFrame(positions);
	UpdateVertexBuffer();
	SetAlpha(alpha);
	shader.SetUniformMath4f("u_MVP", mvp);
	Renderer::Draw(va, *ib, shader);
}

void Sprite::Draw()
{
	Draw(m_Alpha);
}

void Sprite::UpdateVertexBuffer()
{
	vb.Bind();
	va.Bind();
	va.AddBuffer(vb, layout);

	glBufferData(GL_ARRAY_BUFFER, 4 *4 * sizeof(float), positions, GL_DYNAMIC_DRAW);
}

void Sprite::SetFullTexture()
{
	float fullSizedPositions[]
	{
		-0.5f,-0.5f, 0.0f, 0.0f,
		0.5f,-0.5f, 1.0f, 0.0f,
		0.5f,0.5f, 1.0f, 1.0f,
		-0.5f,0.5f, 0.0f, 1.0f
	};

	for (int i = 0; i < 16; i++)
	{
		positions[i] = fullSizedPositions[i];
	}
}