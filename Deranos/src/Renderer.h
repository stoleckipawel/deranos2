#pragma once
#include <Camera.h>

#include <Model.h>
#include <Mesh.h>
#include <Texture.h>
#include "Shader.h"
#include <Transform.h>
#include <Window.h>

class Renderer
{
public:
	void PreRender();
	void Renderloop();
	void Present();
	void BindWindow(std::shared_ptr<Window> window);
	void OnInput();
private:
	void ClearBackBuffer(glm::vec3 clear_color);
	void WireframeMode();

	std::shared_ptr<Window> m_window;

	std::shared_ptr<Model> m_model;

	std::shared_ptr<Transform> m_model_transform;

	std::shared_ptr<Camera> m_camera;
	std::shared_ptr<Texture> m_texture;
	std::shared_ptr<Shader> m_shader;
};



