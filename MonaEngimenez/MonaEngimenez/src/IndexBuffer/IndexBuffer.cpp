#include "IndexBuffer.h"

#include "Debugger/Debugger.h"

#include <glew.h>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	: m_Count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	DebuggerCall(glGenBuffers(1, &m_RendererID));
	DebuggerCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	DebuggerCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	DebuggerCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
	DebuggerCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::Unbind() const
{
	DebuggerCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
