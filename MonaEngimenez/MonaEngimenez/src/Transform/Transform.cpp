#include "Transform.h"

glm::mat4 Transform::view;
glm::mat4 Transform::proj;

void Transform::Init()
{
	proj = glm::ortho(0.0f, 1024.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
}


glm::mat4 Transform::TRStoMVP(glm::vec3 translation, float rotation, glm::vec3 scale)
{
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, translation);
	model = glm::rotate(model, rotation, glm::vec3(0, 0, 1));
	model = glm::scale(model, scale);

	return proj * view * model;
}
