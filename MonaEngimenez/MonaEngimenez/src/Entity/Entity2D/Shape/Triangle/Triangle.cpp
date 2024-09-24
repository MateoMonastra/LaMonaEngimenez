#include "Triangle.h"

#include "Renderer/Renderer.h"
#include "Transform/Transform.h"

Triangle::Triangle(BufferLayout layout, float width, float height)
{
	float positions[]
	{
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.0f,0.5f,
	};

	this->width = width;
	this->height = height;

	glm::mat4 mvp = Transform::Scale(model, glm::vec3(width, height, 0.0f));

	shader.SetShader("../MonaEngimenez/src/Shaders/Basic.shader");

	Bind(mvp);

	vb.SetVertexBuffer(positions, 4 * 2 * sizeof(float));
	va.AddBuffer(vb, layout);

	vb.Unbind();
	va.Unbind();
}

Triangle::~Triangle()
{
	shader.Unbind();
}
