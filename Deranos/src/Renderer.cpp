#include "pch.h"
#include "Renderer.h"
#include "Gui.h"

Renderer::Renderer(std::shared_ptr<Window>& window)
	: m_window(window)
{
}

void Renderer::ClearBackBuffer(glm::vec3 clear_color = glm::vec3(0.0, 0.0, 0.0))
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::WireframeMode()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//wireframe mode
}

void Renderer::PreRender()
{
	m_gui = std::make_shared<Gui>(m_window);

	m_camera = std::make_shared<Camera>(m_window);
	m_camera->Translate(glm::vec3(0.0f, 0.0f, -3.0f));

	m_model = std::make_shared<Model>();

	m_texture = std::make_shared<Texture>("resources/textures/container.jpg", true);

	m_shader = std::make_shared<Shader>("src/shaders/simple.vs", "src/shaders/simple.ps");

	m_model_transform = std::make_shared<Transform>();
}
bool test = false;
float test2 = 0.0f;
float color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
float pos[3] = {0.0f, 0.0f, 0.0f};

void Renderer::DrawGui()
{
	m_gui->Init();
	m_gui->Checkbox("Checkbox", test);
	m_gui->Slider("Slider", test2, 0.0, 1.0);
	
	m_gui->Drag("Camera Position", pos);
	//m_camera->SetPosition(pos[0], pos[1], pos[2]);

	
	m_gui->Color("Color", color);
	m_gui->Render();
}

void Renderer::Renderloop()
{
	//Renderloop ->
	Renderer::ClearBackBuffer(glm::vec3(1.0, 0.0, 1.0));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

	glEnable(GL_DEPTH_TEST);

	m_model_transform->SetPosition(0.5f, 0.0f, 0.0f);
	m_model_transform->SetRotation(1.0f, 1.0f, 1.0f);
	m_model_transform->SetScale(1.25);
	m_model_transform->Rotate((float)glfwGetTime() * 0.5, 0.0f, 0.0f);

	m_texture->Bind();

	m_shader->Bind();
	m_shader->setInt("ourTexture", 0);
	m_shader->setMat4("model", m_model_transform->GetMatrix());
	m_shader->setMat4("view", m_camera->GetViewMatrix());
	m_shader->setMat4("projection", m_camera->GetProjectionMatrix());

	m_model->Draw();

	this->DrawGui();
}

void Renderer::Present()
{	
	glfwSwapBuffers(m_window->GetWindow());
}

void Renderer::BindWindow(std::shared_ptr<Window>& window)
{
	m_window = window;
}

void Renderer::OnInput()
{
	m_camera->OnInput();
}