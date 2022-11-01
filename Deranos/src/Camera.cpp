#include "pch.h"
#include "Camera.h"

Camera::Camera(std::shared_ptr<Window>& window)
	: m_window(window),
	fov(45.0f), 
	near_clipping_plane(0.01f), 
	far_clipping_plane(1000.0), 
	speed(0.01f),
	position(glm::vec3(0.0f, 0.0f, 0.0f)),
	rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
	m_target(glm::vec3(0.0f, 0.0f, 1.0f)),
	m_left(glm::vec3(-1.0f, 0.0f, 0.0f)),
	m_right(glm::vec3(1.0f, 0.0f, 0.0f))
{
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(position, m_target, m_up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return glm::perspective(glm::radians(fov), static_cast<float>(m_window->GetWidth()) / m_window->GetHeight(), near_clipping_plane, far_clipping_plane);
}

void Camera::OnInput()
{
	Input input;//Input should take window in constructor
	
	if(input.IsKeyPressed(GLFW_KEY_W, m_window))
		position += m_target * speed;

	if (input.IsKeyPressed(GLFW_KEY_S, m_window))
		position += m_target * -speed;

	if (input.IsKeyPressed(GLFW_KEY_A, m_window))
		position += m_left * speed;

	if (input.IsKeyPressed(GLFW_KEY_D, m_window))
		position += m_right * speed;
}