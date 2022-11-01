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
	glm::float32 sensitivity;
	glm::vec3 position_ws;
	glm::vec3 orientation;
private:
	void Rotation();
	void Translation();
	std::shared_ptr<Window>& m_window;
	std::shared_ptr<Input> m_input;

	glm::vec3 m_up;
	bool m_in_rotation = true;
};
