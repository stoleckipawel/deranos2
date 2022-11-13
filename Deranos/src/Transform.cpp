#include "pch.h"
#include "Transform.h"

Transform::Transform()
	: m_scale(glm::vec3(1.0f, 1.0f, 1.0f)), 
	m_position(glm::vec3(0.0f, 0.0f, 0.0f)), 
	m_rotation(glm::vec3(0.0f, 0.0f, 0.0f))
{
}

void Transform::SetScale(float scale)
{
	m_scale.x = scale;
	m_scale.y = scale;
	m_scale.z = scale;
}

glm::vec3 Transform::GetScale()
{
	return m_scale;
}

void Transform::SetScale(float x, float y, float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

void Transform::Translate(float x, float y, float z)
{
	m_position.x += x;
	m_position.y += y;
	m_position.z += z;
}

void Transform::Translate(glm::vec3 xyz)
{
	m_position += xyz;
}

void Transform::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

glm::vec3 Transform::GetPosition()
{
	return m_position;
}

void Transform::SetRotation(float x, float y, float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

glm::vec3 Transform::GetRotation()
{
	return m_rotation;
}

void Transform::Rotate(float x, float y, float z)
{
	m_rotation.x += x;
	m_rotation.y += y;
	m_rotation.z += z;
}

glm::mat4 Transform::GetMatrix()
{
	glm::mat4 model_mtx = glm::mat4(1.0f);
	model_mtx = glm::translate(model_mtx, m_position);
	//model_mtx = glm::rotate(model_mtx, glm::radians(360.0f), m_rotation);
	model_mtx = glm::scale(model_mtx, m_scale);
	return model_mtx;
}
