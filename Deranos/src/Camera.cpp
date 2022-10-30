#include "pch.h"
#include "Camera.h"

Camera::Camera(std::shared_ptr<Window>& window)
	: 
	m_window(window),
	m_fov(40.5f), 
	m_near_clipping_plane(0.01f), 
	m_far_clipping_plane(1000.0), 
	m_speed(0.01f),
	m_position(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_rotation(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
	m_target(glm::vec3(0.0f, 0.0f, 1.0f)),
	m_left(glm::vec3(-1.0f, 0.0f, 0.0f)),
	m_right(glm::vec3(1.0f, 0.0f, 0.0f))
{

}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(m_position, m_target, m_up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return glm::perspective(glm::radians(m_fov), static_cast<float>(m_window->GetWidth()) / m_window->GetHeight(), m_near_clipping_plane, m_far_clipping_plane);
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

void Camera::OnInput()
{
	Input input;//Input should take window in constructor
	
	if(input.IsKeyPressed(GLFW_KEY_W, m_window))
		Translate(m_target * m_speed);

	if (input.IsKeyPressed(GLFW_KEY_S, m_window))
		Translate(m_target * -m_speed);

	if (input.IsKeyPressed(GLFW_KEY_A, m_window))
		Translate(m_left * m_speed);

	if (input.IsKeyPressed(GLFW_KEY_D, m_window))
		Translate(m_right * m_speed);
}