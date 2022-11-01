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

	float fov;
	float near_clipping_plane;
	float far_clipping_plane;
	glm::float32 speed;
	glm::vec3 position;
	glm::vec3 rotation;
private:
	glm::vec3 m_up;
	glm::vec3 m_target;
	glm::vec3 m_left;
	glm::vec3 m_right;
	std::shared_ptr<Window>& m_window;
};
