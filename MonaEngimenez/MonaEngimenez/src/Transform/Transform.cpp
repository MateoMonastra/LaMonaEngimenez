#include "Transform.h"

glm::mat4 Transform::view;
glm::mat4 Transform::proj;

void Transform::Init()
{
	proj = glm::ortho(0.0f, 1024.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
}

glm::mat4 Transform::Translate(glm::mat4& model, glm::vec3 translation)
{
	model = glm::translate(model, translation);
	return proj * view * model;
}

void Transform::Rotate(glm::mat4& model, float angle, glm::vec3 axis)
{
}

void Transform::Scale(glm::mat4& model, glm::vec3 scale)
{
}