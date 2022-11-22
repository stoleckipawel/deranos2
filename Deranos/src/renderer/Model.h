#pragma once

#include <Mesh.h>
#include <Material.h>
#include <Transform.h>
#include <Camera.h>

class Model
{
public:
	Model();
	Model(const char* path);
	void Draw(Camera& camera);


	std::shared_ptr<Material> material;
	std::shared_ptr<Transform> model_xform;
	std::vector<std::shared_ptr<Mesh>> mesh;
private:
	void LoadModel(std::string path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	void ProcessMesh(aiMesh* mesh, const aiScene* scene);
};

