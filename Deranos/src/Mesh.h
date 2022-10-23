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
    Mesh(std::vector<VertexLayout>);
    ~Mesh();
private:
};

