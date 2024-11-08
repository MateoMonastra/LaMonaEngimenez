#include "Sprite.h"

#include "Debugger/Debugger.h"

#include "vendor/stb_image.h"

Sprite::Sprite(const std::string& path)
	: m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)

{
	float positions[]
	{
		-0.5f,-0.5f, 0.0f, 0.0f,
		0.5f,-0.5f, 1.0f, 0.0f,
		0.5f,0.5f, 1.0f, 1.0f,
		-0.5f,0.5f, 0.0f, 1.0f
	};

	unsigned int indices[]
	{
		0,1,2,
		2,3,0
	};

	SetScale(glm::vec3(1.0f, 1.0f, 0.0f));
	SetRotation(0.0f);
	SetTranslation(0.0f, 0.0f);

	DebuggerCall(glEnable(GL_BLEND));
	DebuggerCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	shader.SetShader("../Resources/Basic.shader");
	
	layout.Push<float>(2);
	layout.Push<float>(2);

	ib = new IndexBuffer(indices, 6);

	vb.SetVertexBuffer(positions, 4 * 4 * sizeof(float));
	va.AddBuffer(vb, layout);

	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

	DebuggerCall(glGenTextures(1, &m_RendererID));
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	
	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	DebuggerCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	
	glGenerateMipmap(GL_TEXTURE_2D);

	DebuggerCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);

	Bind();

	shader.SetUniform1i("u_Texture", 0);

	scaleFactorX = m_Width;
	scaleFactorY = m_Height;

	vb.Unbind();
	va.Unbind();
	ib->Unbind();
}

Sprite::~Sprite()
{
	DebuggerCall(glDeleteTextures(1, &m_RendererID));
}

void Sprite::Bind(unsigned int slot) const
{
	DebuggerCall(glActiveTexture(GL_TEXTURE0 + slot));
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Sprite::Unbind() const
{
	DebuggerCall(glBindTexture(GL_TEXTURE_2D, 0));
}

void Sprite::Draw(float alpha)
{
	SetAlpha(alpha);
	shader.SetUniformMath4f("u_MVP", mvp);
	Renderer::Draw(va, *ib, shader);
}

void Sprite::Draw()
{
	Draw(m_Alpha);
}

void Sprite::SetAlpha(float alpha)
{
	m_Alpha = alpha;
	shader.SetUniform1f("u_Alpha", m_Alpha);
}
