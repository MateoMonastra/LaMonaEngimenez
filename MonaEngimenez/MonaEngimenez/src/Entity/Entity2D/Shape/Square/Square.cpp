#include "Square.h"

Square::Square(float width, float height)
{
	float positions[]
	{
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.5f,0.5f,
		-0.5f,0.5f,
	};

	unsigned int indices[]
	{
		0,1,2,
		2,3,0
	};

	ib = new IndexBuffer(indices, 6);

	this->width = width;
	this->height = height;

	SetScale(glm::vec3(width, height, 0.0f));

	shader->SetShader("../Resources/Shape.shader");

	vb.SetVertexBuffer(positions, 4 * 2 * sizeof(float));
	va.AddBuffer(vb, layout);

	vb.Unbind();
	va.Unbind();
	ib->Unbind();
}

Square::~Square()
{
	shader->Unbind();
}
