#include "Sprite.h"

#include "Debugger/Debugger.h"



Sprite::Sprite(const std::string& path)
	: m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)

{
	unsigned int indices[]
	{
		0,1,2,
		2,3,0
	};

	//id = instanceCount++;
	// = id;

	//Renderer::EnableBlending();

	SetFullTexture();

	SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	SetRotation(0.0f);
	SetTranslation(0.0f, 0.0f);

	layout.Push<float>(2);
	layout.Push<float>(2);

	ib = new IndexBuffer(indices, 6);

	vb.SetVertexBuffer(positions, 4 * 4 * sizeof(float));
	va.AddBuffer(vb, layout);

	m_FilePath = path;

	this->shader = Renderer::GetShader();

	Renderer::LoadImage(path, m_RendererID, m_Width, m_Height, m_BPP, m_LocalBuffer, id);
	

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
	animation->SetCurrentFrame(0);
	animation->GetFrame(positions);
	UpdateVertexBuffer();
	SetAlpha(alpha);
	shader->Bind();
	shader->SetUniformMath4f("u_MVP", mvp);
	shader->SetUniform1f("u_Alpha", m_Alpha);

	Renderer::BindTexture(m_RendererID, id);
	Renderer::Draw(va, *ib, m_RendererID);
}

void Sprite::Draw()
{
	Draw(m_Alpha);
}

void Sprite::Animate()
{
	animation->Update();
	animation->GetFrame(positions);
	UpdateVertexBuffer();
	shader->Bind();
	shader->SetUniformMath4f("u_MVP", mvp);
	shader->SetUniform1f("u_Alpha", m_Alpha);

	Renderer::BindTexture(m_RendererID, id);
	Renderer::Draw(va, *ib, m_RendererID);
}

void Sprite::UpdateVertexBuffer()
{
	vb.Bind();
	va.Bind();
	va.AddBuffer(vb, layout);

	glBufferData(GL_ARRAY_BUFFER, 4 *4 * sizeof(float), positions, GL_DYNAMIC_DRAW);

	vb.Unbind();
	va.Unbind();
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