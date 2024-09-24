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
	//static glm::mat4 Translate(glm::mat4& model, glm::vec3 translation);
	//static glm::mat4 Rotate(glm::mat4& model, float angle, float width, float height);
	//static glm::mat4 Scale(glm::mat4& model, glm::vec3 scale);
	static glm::mat4 TRStoMVP(glm::vec3 translation, float rotation, glm::vec3 scale);
};

