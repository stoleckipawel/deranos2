#pragma once
#include <Camera.h>

class Renderer
{
public:
	Renderer();
	~Renderer();
	static void PreRender();
	static void Render();
	static void Present();
private:
	static void ClearBackBuffer(glm::vec3 clear_color);

	//static Camera* m_camera;
};



