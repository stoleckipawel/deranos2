#include "pch.h"
#include "Mesh.h"

Mesh::Mesh()
{
	Mesh::LoadMesh();

	glGenVertexArrays(1, &m_vao);

	glGenBuffers(1, &m_vbo);
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertecies[0]) * m_vertecies.size(), &m_vertecies[0], GL_DYNAMIC_DRAW);

	glGenBuffers(1, &m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indecies[0]) * m_indecies.size(), &m_indecies[0], GL_DYNAMIC_DRAW);

	//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, position));
	glEnableVertexAttribArray(0);
	//vertex color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, color));
	glEnableVertexAttribArray(1);
	//uvs
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, uv0));
	glEnableVertexAttribArray(2);
}

void Mesh::LoadMesh()
{
	VertexLayout vertex;
	//vert1 // top right
	vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertex.color = glm::vec3(1.0f, 0.0f, 0.0f);
	vertex.uv0 = glm::vec2(1.0f, 1.0f);
	m_vertecies.push_back(vertex);
	//vert2 // bottom right
	vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);
	vertex.uv0 = glm::vec2(1.0f, 0.0f);
	m_vertecies.push_back(vertex);
	//vert3 // bottom left
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertex.color = glm::vec3(0.0f, 0.0f, 1.0f);
	vertex.uv0 = glm::vec2(0.0f, 0.0f);
	m_vertecies.push_back(vertex);
	//vert4 // top left
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertex.color = glm::vec3(1.0f, 1.0f, 0.0f);
	vertex.uv0 = glm::vec2(0.0f, 1.0f);
	m_vertecies.push_back(vertex);

	//incex buffer
	std::vector<unsigned int> indices;
	m_indecies.push_back(0);
	m_indecies.push_back(1);
	m_indecies.push_back(3);
	m_indecies.push_back(1);
	m_indecies.push_back(2);
	m_indecies.push_back(3);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ebo);
}

void Mesh::BindVertexArray()
{
	glBindVertexArray(m_vao);
}

void Mesh::Draw()
{
	BindVertexArray();
	glDrawElements(GL_TRIANGLES, m_indecies.size(), GL_UNSIGNED_INT, 0);
}