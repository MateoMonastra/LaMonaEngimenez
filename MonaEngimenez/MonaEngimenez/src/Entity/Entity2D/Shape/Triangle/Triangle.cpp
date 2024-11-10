#include "Triangle.h"


Triangle::Triangle(float width, float height)
{
	float positions[]
	{
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.0f,0.5f,
	};

	unsigned int indices[]
	{
		0,1,2,
	};

	ib = new IndexBuffer(indices, 3);

	this->width = width;
	this->height = height;

	SetScale(glm::vec3(width, height, 0.0f));

	shader.SetShader("../Resources/Shape.shader");

	vb.SetVertexBuffer(positions, 4 * 2 * sizeof(float));
	va.AddBuffer(vb, layout);

	vb.Unbind();
	va.Unbind();
	ib->Unbind();
}

Triangle::~Triangle()
{
	shader.Unbind();
}
