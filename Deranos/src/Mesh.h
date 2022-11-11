#pragma once

struct VertexLayout
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv0;
    glm::vec3 normal;
};

class Mesh
{
public:
    Mesh();
    ~Mesh();
    void Draw();
    void SetVertecies(std::vector<VertexLayout>& vertecies);
    void SetIndecies(std::vector<unsigned int>& indecies);
    void RetrieveVertecies(aiMesh* mesh);
    void RetrieveIndeces(aiMesh* mesh);
private:
    void BindVertexArray();
    void Clear();
    void LoadQuad();

    std::vector<VertexLayout> m_vertecies;
    std::vector<unsigned int> m_indecies;
    
    unsigned int m_vao;
    unsigned int m_vbo;
    unsigned int m_ebo;
};

