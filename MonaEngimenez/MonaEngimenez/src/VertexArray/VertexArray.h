#pragma once
#include "Exporter.h"

#include "VertexBuffer/VertexBuffer.h"
#include "BufferLayout/BufferLayout.h"


class VertexArray
{
private:

	unsigned int m_RendererID;


public:

	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const BufferLayout& layout);
	void Bind() const;
	void Unbind() const;
};