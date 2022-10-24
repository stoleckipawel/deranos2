#include "pch.h"
#include "Camera.h"

Camera::Camera()
{
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(m_position, m_target, m_up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return glm::perspective(glm::radians(m_fov), (float)900 / (float)900.0, m_near_clipping_plane, m_far_clipping_plane);
}

float Camera::GetFov()
{
	return m_fov;
}

void Camera::SetFov(float angle)
{
	m_fov = angle;
}

void Camera::SetNearClippingPlane(float distance)
{
	m_near_clipping_plane = distance;
}
void Camera::SetFarClippingPlane(float distance)
{
	m_far_clipping_plane = distance;
}

void Camera::Translate(float x, float y, float z)
{
	m_position.x += x;
	m_position.y += y;
	m_position.z += z;
}

void Camera::Translate(glm::vec3 xyz)
{
	m_position += xyz;
}

void Camera::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

glm::vec3 Camera::GetPosition()
{
	return m_position;
}

void Camera::SetRotation(float x, float y, float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

void Camera::Rotate(float x, float y, float z)
{
	m_rotation.x += x;
	m_rotation.y += y;
	m_rotation.z += z;
}

glm::vec3 Camera::GetRotation()
{
	return m_rotation;
}

void Camera::OnInput(std::shared_ptr<Window> window)
{
	Input input;//Input should take window in constructor
	
	if(input.IsKeyPressed(GLFW_KEY_UP, window))
		Translate(m_target * m_speed);

	if (input.IsKeyPressed(GLFW_KEY_DOWN, window))
		Translate(m_target * -m_speed);

	if (input.IsKeyPressed(GLFW_KEY_LEFT, window))
		Translate(m_left * m_speed);

	if (input.IsKeyPressed(GLFW_KEY_RIGHT, window))
		Translate(m_right * m_speed);
}