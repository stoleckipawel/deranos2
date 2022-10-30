#pragma once

#include <Mesh.h>

class Model
{
public:
	Model();
	void Draw();
	std::shared_ptr<Mesh> GetMesh();
private:
	void LoadMesh();

	std::shared_ptr<Mesh> m_mesh;
};

