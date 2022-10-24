#include "pch.h"
#include "Renderer.h"

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
	//check how many vertex attrib there is
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	//Camera Setup
	m_camera = std::make_shared<Camera>();
	m_camera->SetFov(45.0f);
	m_camera->SetNearClippingPlane(0.01);
	m_camera->SetFarClippingPlane(1000.0);
	m_camera->Translate(0.0f, 0.0f, -3.0f);


	std::vector<VertexLayout> plane;
	VertexLayout vertex;
	//vert1 // top right
	vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertex.color = glm::vec3(1.0f, 0.0f, 0.0f);
	vertex.uv0 = glm::vec2(1.0f, 1.0f);
	plane.push_back(vertex);
	//vert2 // bottom right
	vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);
	vertex.uv0 = glm::vec2(1.0f, 0.0f);
	plane.push_back(vertex);
	//vert3 // bottom left
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertex.color = glm::vec3(0.0f, 0.0f, 1.0f);
	vertex.uv0 = glm::vec2(0.0f, 0.0f);
	plane.push_back(vertex);
	//vert4 // top left
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertex.color = glm::vec3(1.0f, 1.0f, 0.0f);
	vertex.uv0 = glm::vec2(0.0f, 1.0f);
	plane.push_back(vertex);

	//incex buffer
	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	m_mesh = std::make_shared<Mesh>(plane, indices);

	m_texture = std::make_shared<Texture>("resources/textures/container.jpg", true);

	m_shader = std::make_shared<Shader>("src/shaders/simple.vs", "src/shaders/simple.ps");

	m_model_transform = std::make_shared<Transform>();
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

	m_mesh->Draw();
}

void Renderer::Present()
{	
	glfwSwapBuffers(m_window->GetWindow());
}

void Renderer::BindWindow(std::shared_ptr<Window> window)
{
	m_window = window;
}

void Renderer::OnInput()
{
	m_camera->OnInput(m_window);
}