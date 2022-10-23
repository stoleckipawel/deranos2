#include "pch.h"
#include "Mesh.h"

Mesh::Mesh(std::vector<VertexLayout> vertecies, std::vector<unsigned int> indecies)
{
	m_vertecies = vertecies;
	m_indecies = indecies;

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