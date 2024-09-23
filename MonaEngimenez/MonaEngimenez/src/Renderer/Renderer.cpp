#include "Renderer.h"


#include "Debugger/Debugger.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

MONA_ENGIMENEZ void Renderer::CreateBuffer(float* positions, int* indices, int positionSize, int indicesSize, int attribVertexSize, unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * positionSize, positions, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indicesSize, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, attribVertexSize, GL_FLOAT, GL_FALSE, attribVertexSize * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void Renderer::Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	DebuggerCall(glClearColor(red, green, blue, alpha));
	DebuggerCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::SwapBuffers(Window window)
{
	DebuggerCall(glfwSwapBuffers(window.GetWindow()));
}

MONA_ENGIMENEZ void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();

	DebuggerCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
