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
	void Draw(std::shared_ptr<Camera>& camera);

	void AttachMaterial(std::shared_ptr<Material>& material);
	
	std::shared_ptr<Material> material;
	std::shared_ptr<Transform> model_xform;
	std::vector<std::shared_ptr<Mesh>> mesh;
private:
	void LoadModel(const char* path);
};

