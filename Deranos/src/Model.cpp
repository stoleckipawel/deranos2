#include "pch.h"
#include "Model.h"

Model::Model()
{
	//Dummy Model Implementation
	mesh.push_back(std::make_shared<Mesh>());
	model_xform = std::make_shared<Transform>();
	material = std::make_shared<Material>();
}

Model::Model(const char* path)
{
	Model::LoadModel(path);
}

void Model::LoadModel(const char* path)
{

}

void Model::AttachMaterial(std::shared_ptr<Material>& material)
{
	this->material = material;
}

void Model::Draw(std::shared_ptr<Camera>& camera)
{
	//Set proper camera consts in  the material, model, view, projection xform in the material
	material->Bind(camera, model_xform);

	//Draw each sub mesh of the mesh
	for each (auto submesh in mesh)
	{
		submesh->Draw();
	}
}


