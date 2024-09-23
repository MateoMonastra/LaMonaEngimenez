#include "Shape.h"
#include "Renderer/Renderer.h"

#include <glm.hpp>


Shape::Shape(Renderer* renderer, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
	: Entity2D(renderer, position, scale, rotation)
{
	
}

void Shape::Draw()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, 0);
}