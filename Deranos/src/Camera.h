#pragma once
class Camera
{
public:
	void OnKeyboard(unsigned char key);

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
	float m_fov = 45.0f;
	float m_near_clipping_plane;
	float m_far_clipping_plane;
	glm::float32 m_speed = 1.0f;

	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_rotation = glm::vec3(1.0f, 1.0f, 1.0f);

	glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 m_target = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 m_left = glm::normalize(glm::cross(m_target, m_up));
	glm::vec3 m_right = glm::normalize(glm::cross(m_up, m_target));


};

