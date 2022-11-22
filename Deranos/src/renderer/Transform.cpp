#include "pch.h"
#include "Transform.h"

Transform::Transform()
	: scale(glm::vec3(1.0f, 1.0f, 1.0f)), 
	position(glm::vec3(0.0f, 0.0f, 0.0f)), 
	rotation(glm::vec3(0.0f, 0.0f, 0.0f))
{
}

glm::mat4 Transform::GetMatrix()
{
	glm::mat4 model_mtx = glm::mat4(1.0f);
	model_mtx = glm::translate(model_mtx, position);
	//to do rotation
	model_mtx = glm::scale(model_mtx, scale);
	return model_mtx;
}
