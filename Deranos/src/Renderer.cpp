#include "pch.h"
#include "Renderer.h"
#include "Gui.h"
#include "Button.h"


Renderer::Renderer(std::shared_ptr<Window>& window)
	: m_window(window)
{
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

	ImGui::Begin("Camera");
		Button::Drag("Position", m_camera->position_ws);
		Button::Drag("Rotation", m_camera->orientation);
		Button::Slider("Field of View", m_camera->fov, 1.0f, 180.0f);
	ImGui::End();

	m_gui->Render();
}

void Renderer::PreRender()
{
	m_gui = std::make_shared<Gui>(m_window);

	m_camera = std::make_shared<Camera>(m_window);
	m_camera->position_ws = glm::vec3(0.0f, 0.0f, 3.0f);

	m_model = std::make_shared<Model>();
}

void Renderer::Renderloop()
{
	Renderer::ClearBackBuffer(glm::vec3(1.0, 0.0, 1.0));
	Renderer::ClearZbuffer();

	m_model->Draw(m_camera);

	Renderer::DrawGui();
}

void Renderer::Present()
{	
	glfwSwapBuffers(m_window->GetWindow());
}

void Renderer::OnInput()
{
	m_camera->OnInput();
}