#include "VertexBuffer.h"

#include "Debugger/Debugger.h"

#include <glew.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	DebuggerCall(glGenBuffers(1, &m_RendererID));
	DebuggerCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	DebuggerCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	DebuggerCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
	DebuggerCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
	DebuggerCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
