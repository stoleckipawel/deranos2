#include "pch.h"
#include "Model.h"

Model::Model()
{
	LoadMesh();
}

void Model::Draw()
{
	m_mesh->Draw();
}

std::shared_ptr<Mesh> Model::GetMesh()
{
	return m_mesh;
}

void Model::LoadMesh()
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

	m_mesh = std::make_shared<Mesh>(plane, indices);
}