#include "pch.h"
#include "Renderer.h"
#include "Gui.h"
#include "Button.h"


Renderer::Renderer(Window& window)
	: m_window(window)
{
	m_gui = std::make_shared<Gui>(m_window);

	m_camera = std::make_shared<Camera>(m_window);

	m_scene = std::make_shared<Scene>(*m_camera);
}

void Renderer::ClearBackBuffer(glm::vec3 clear_color = glm::vec3(0.0, 0.0, 0.0))
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearZbuffer()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::WireframeMode()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//wireframe mode
}

void Renderer::DrawGui()
{
	m_gui->Init();

	ImGui::Begin("Editor");
		ImGui::Text("Camera");
		Button::Drag("Position", m_camera->position_ws);
		Button::Drag("Rotation", m_camera->orientation);
		Button::Slider("Field of View", m_camera->fov, 1.0f, 180.0f);
		ImGui::Separator();

		ImGui::Text("Backpack");
		Button::Drag("Position ", m_backpack->model_xform->position);
		Button::Drag("Scale", m_backpack->model_xform->scale);
		ImGui::Separator();

		ImGui::Text("Cube");
		Button::Drag("Position  ", m_cube->model_xform->position);
		Button::Drag("Scale ", m_cube->model_xform->scale);
	ImGui::End();

	m_gui->Render();
}

void Renderer::LoadModels()
{
	m_backpack = std::make_shared<Model>("resources/models/backpack/backpack.obj");//
	m_backpack->model_xform->position += glm::vec3(-1.0, 0.0, -5.0f);
	m_scene->models.push_back(m_backpack);

	m_cube = std::make_shared<Model>("resources/models/cube/cube.obj");
	m_cube->model_xform->position += glm::vec3(4.3, 4.0, -16.050f);
	m_cube->model_xform->scale += glm::vec3(3.0, 3.0, 3.0f);
	m_scene->models.push_back(m_cube);
}

void Renderer::PreRender()
{
	LoadModels();
}

void Renderer::Renderloop()
{
	ClearBackBuffer(glm::vec3(0.0, 0.0, 1.0));
	ClearZbuffer();

	m_scene->Draw();

	DrawGui();
}

void Renderer::Present()
{	
	glfwSwapBuffers(m_window.GetWindow());
}

void Renderer::OnInput()
{
	m_camera->OnInput();
}