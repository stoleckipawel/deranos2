#pragma once

struct VertexLayout
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv0;
};

class Mesh
{
public:
    Mesh(std::vector<VertexLayout> vertecies, std::vector<unsigned int> indecies);
    ~Mesh();
    void Draw();
private:
    void BindVertexArray();

    std::vector<VertexLayout> m_vertecies;
    std::vector<unsigned int> m_indecies;
    
    unsigned int m_vao;
    unsigned int m_vbo;
    unsigned int m_ebo;
};

