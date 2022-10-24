#pragma once
#include <Camera.h>

#include <Mesh.h>
#include <Texture.h>
#include "Shader.h"
#include <Transform.h>

class Renderer
{
public:
	void PreRender();
	void Render();
	void Present();
private:
	void ClearBackBuffer(glm::vec3 clear_color);
	void WireframeMode();

	std::shared_ptr<Mesh> m_mesh;
	std::shared_ptr<Transform> m_model_transform;

	std::shared_ptr<Camera> m_camera;
	std::shared_ptr<Texture> m_texture;
	std::shared_ptr<Shader> m_shader;
};



