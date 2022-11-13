#include "pch.h"
#include "Camera.h"

Camera::Camera(Window& window)
	: m_window(window),
	fov(45.0f), 
	near_clipping_plane(0.01f), 
	far_clipping_plane(1000.0), 
	speed(0.01f),
	sensitivity(100.0f),
	position_ws(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
	orientation(glm::vec3(0.0f, 0.0f, -1.0f))
{
	m_input = std::make_shared<Input>();//to be converted into singleton
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(position_ws, position_ws + orientation, m_up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return glm::perspective(glm::radians(fov), static_cast<float>(m_window.GetWidth()) / m_window.GetHeight(), near_clipping_plane, far_clipping_plane);
}

void Camera::Rotation()
{
	if (m_input->IsMouseButtonPressed(GLFW_MOUSE_BUTTON_MIDDLE, m_window))
	{
		if (m_in_rotation)
		{
			glfwSetCursorPos(m_window.GetWindow(), m_window.GetWidth() / 2.0, m_window.GetHeight() / 2.0);
			m_in_rotation = false;
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(m_window.GetWindow(), &mouseX, &mouseY);

		float rotX = sensitivity * (float)(mouseY - (m_window.GetHeight() / 2.0)) / m_window.GetHeight();
		float rotY = sensitivity * (float)(mouseX - (m_window.GetHeight() / 2.0)) / m_window.GetHeight();

		glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, m_up)));

		// Decides whether or not the next vertical Orientation is legal or not
		if (abs(glm::angle(newOrientation, m_up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			orientation = newOrientation;
		}

		// Rotates the Orientation left and right
		orientation = glm::rotate(orientation, glm::radians(-rotY), m_up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(m_window.GetWindow(), m_window.GetWidth() / 2.0, m_window.GetHeight() / 2.0);
	}
	else
	{
		m_in_rotation = true;
	}
}

void Camera::Translation()
{
	/*
	if (m_input->IsKeyPressed(GLFW_KEY_LEFT_SHIFT, m_window))
		position_ws -= speed * m_up;

	*/
	if (m_input->IsKeyPressed(GLFW_KEY_SPACE, m_window))
		position_ws += speed * m_up;

	if (m_input->IsKeyPressed(GLFW_KEY_LEFT_CONTROL, m_window))
		position_ws -= speed * m_up;

	if (m_input->IsKeyPressed(GLFW_KEY_W, m_window))
		position_ws += speed * orientation;

	if (m_input->IsKeyPressed(GLFW_KEY_S, m_window))
		position_ws -= speed * orientation;

	if (m_input->IsKeyPressed(GLFW_KEY_A, m_window))
		position_ws -= speed * glm::normalize(glm::cross(orientation, m_up));

	if (m_input->IsKeyPressed(GLFW_KEY_D, m_window))
		position_ws += speed * glm::normalize(glm::cross(orientation, m_up));
}

void Camera::OnInput()
{
	//#ToDo: this should be event based not milions if every frame (callbacks)
	Translation();
	Rotation();
}