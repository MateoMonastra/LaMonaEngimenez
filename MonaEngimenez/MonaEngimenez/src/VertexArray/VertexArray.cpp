#include "VertexArray.h"

#include "Debugger/Debugger.h"

VertexArray::VertexArray()
{
	DebuggerCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
	DebuggerCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const BufferLayout& layout)
{
	Bind();
	vb.Bind();
	
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];

		DebuggerCall(glEnableVertexAttribArray(i));

		glVertexAttribPointer(i, element.count, element.type,
			element.normalized, layout.GetStride(), (const void*)offset);

		offset += element.count * BufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	DebuggerCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	DebuggerCall(glBindVertexArray(0));
}
