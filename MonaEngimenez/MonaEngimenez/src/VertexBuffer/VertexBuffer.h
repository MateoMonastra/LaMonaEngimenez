#pragma once
#include "Exporter.h"

class VertexBuffer
{
private:

	unsigned int m_RendererID{};

public:

	VertexBuffer();
	~VertexBuffer();

	void SetVertexBuffer(const void* data, unsigned int size);
	void Bind() const;
	void Unbind() const;
};

