#pragma once
#include "Exporter.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

static class Transform
{
private:
	static glm::mat4 view;
	static glm::mat4 proj;

public:
	static void Init();
	static glm::mat4 Translate(glm::mat4& model, glm::vec3 translation);
	static void Rotate(glm::mat4& model, float angle, glm::vec3 axis);
	static void Scale(glm::mat4& model, glm::vec3 scale);
};

