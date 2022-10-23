#pragma once
#include <Camera.h>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void PreRender();
	void Render();
	void Present();
private:
	void ClearBackBuffer(glm::vec3 clear_color);

	std::shared_ptr<Camera> m_camera;
};



