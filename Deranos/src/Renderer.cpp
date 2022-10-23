#include "pch.h"
#include "Renderer.h"
#include "Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <Transform.h>
#include <Mesh.h>
	

void Renderer::ClearBackBuffer(glm::vec3 clear_color = glm::vec3(0.0, 0.0, 0.0))
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::PreRender()
{
	//check how many vertex attrib there is
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
}

Renderer::Renderer()
{
	//Camera Setup
	m_camera = std::make_shared<Camera>();
	m_camera->SetFov(45.0f);
	m_camera->SetNearClippingPlane(0.01);
	m_camera->SetFarClippingPlane(1000.0);
	m_camera->Translate(0.0f, 0.0f, -3.0f);
}

Renderer::~Renderer()
{

}

void Renderer::Render()
{
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

	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(plane, indices);

	//textures
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("resources/textures/container.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	std::shared_ptr<Shader> simpleShader = std::make_shared<Shader>("src/shaders/simple.vs", "src/shaders/simple.ps");

	std::shared_ptr<Transform> world_transform = std::make_shared<Transform>();
	world_transform->SetPosition(0.5f, 0.0f, 0.0f);
	world_transform->SetScale(1.25);
	world_transform->Rotate((float)glfwGetTime() * 0.5, 0.0f, 0.0f);
	
	//Renderloop
	Renderer::ClearBackBuffer(glm::vec3(1.0, 0.0, 1.0));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!


	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//wireframe mode

	//bind textures
	glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
	glBindTexture(GL_TEXTURE_2D, texture);

	//render objects
	simpleShader->use();
	glEnable(GL_DEPTH_TEST);
	simpleShader->setInt("ourTexture", 0);

	simpleShader->setMat4("model", world_transform->GetMatrix());
	simpleShader->setMat4("view", m_camera->GetViewMatrix());
	simpleShader->setMat4("projection", m_camera->GetProjectionMatrix());

	mesh->Draw();
}

void Renderer::Present()
{	
	//Check events and swap buffers
	//glfwSwapBuffers(window);
}