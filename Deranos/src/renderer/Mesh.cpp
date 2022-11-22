#include "pch.h"
#include "Mesh.h"

Mesh::Mesh(aiMesh* mesh)
{
	RetrieveVertecies(mesh);
	RetrieveIndeces(mesh);

	//RetrieveMaterial
	Build();
}

Mesh::Mesh()
{
	LoadQuad();
	Build();
}

void Mesh::Build()
{
	if (m_vertecies.size() == 0)
	{
		DERANOS_CORE_WARN("MESH::EMPTY VERTEX BUFFER");//TO DO NAME OF THE MESH
		return;
	}


	if (m_indecies.size() == 0)
	{
		DERANOS_CORE_WARN("MESH::EMPTY INDEX BUFFER");//TO DO NAME OF THE MESH 
		return;
	}

	glGenVertexArrays(1, &m_vao);

	glGenBuffers(1, &m_vbo);
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertecies[0]) * m_vertecies.size(), &m_vertecies[0], GL_STATIC_DRAW);

	glGenBuffers(1, &m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indecies[0]) * m_indecies.size(), &m_indecies[0], GL_STATIC_DRAW);

	//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, position));
	glEnableVertexAttribArray(0);
	//vertex color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, color));
	glEnableVertexAttribArray(1);
	//uvs
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, uv0));
	glEnableVertexAttribArray(2);
	//normals
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexLayout), (void*)offsetof(VertexLayout, normal));
	glEnableVertexAttribArray(3);
}

void Mesh::LoadQuad()
{
	Clear();

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
	//#ToDo, check whether a material has been set, if not set a dummy

	BindVertexArray();
	glDrawElements(GL_TRIANGLES, m_indecies.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::Clear()
{
	m_indecies.clear();
	m_vertecies.clear();
}

void Mesh::SetIndecies(std::vector<unsigned int>& indecies)
{
	m_indecies = indecies;
}

void Mesh::SetVertecies(std::vector<VertexLayout>& vertecies)
{
	m_vertecies = vertecies;
}

void Mesh::RetrieveVertecies(aiMesh* mesh)
{
	std::vector<VertexLayout> vertices;//Potentialy needs to be smart pointer, if it doesnt work

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		VertexLayout vertex;
		vertex.position.x = mesh->mVertices[i].x;
		vertex.position.y = mesh->mVertices[i].y;
		vertex.position.z = mesh->mVertices[i].z;

		if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
		{
			vertex.uv0.x = mesh->mTextureCoords[0][i].x;
			vertex.uv0.y = mesh->mTextureCoords[0][i].y;
		}
		else
		{
			vertex.uv0 = glm::vec2(0.0f, 0.0f);
		}

		vertex.normal.x = mesh->mNormals[i].x;
		vertex.normal.y = mesh->mNormals[i].y;
		vertex.normal.z = mesh->mNormals[i].z;

		vertices.push_back(vertex);
	}

	this->SetVertecies(vertices);
}

void Mesh::RetrieveIndeces(aiMesh* mesh)
{
	std::vector<unsigned int> indices;//Potentialy needs to be smart pointer, if it doesnt work

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
			indices.push_back(mesh->mFaces[i].mIndices[j]);
	}

	this->SetIndecies(indices);
}


