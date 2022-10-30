#pragma once
#include <Input.h>
#include <Window.h>

class Camera
{
public:
	Camera(std::shared_ptr<Window>& window);

	void OnInput();

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

	float GetFov();
	void SetFov(float angle);

	void SetNearClippingPlane(float distance);
	void SetFarClippingPlane(float distance);

	void Translate(float x, float y, float z);
	void Translate(glm::vec3 xyz);
	void SetPosition(float x, float y, float z);
	glm::vec3 GetPosition();
	void SetRotation(float x, float y, float z);
	glm::vec3 GetRotation();
	void Rotate(float x, float y, float z);
private:
	float m_fov;
	float m_near_clipping_plane;
	float m_far_clipping_plane;
	glm::float32 m_speed;
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_up;
	glm::vec3 m_target;
	glm::vec3 m_left;
	glm::vec3 m_right;
	std::shared_ptr<Window>& m_window;
};
