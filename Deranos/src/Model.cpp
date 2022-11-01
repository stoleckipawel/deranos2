#include "pch.h"
#include "Model.h"

Model::Model(const char* vertex_shader_path, const char* pixel_shader_path, const char* texture_path)
{
	mesh = std::make_shared<Mesh>();
	model_xform = std::make_shared<Transform>();
	material = std::make_shared<Material>(vertex_shader_path, pixel_shader_path, texture_path);
}

void Model::ResolveTransforms()
{
	model_xform->SetPosition(0.5f, 0.0f, 0.0f);
	model_xform->SetRotation(1.0f, 1.0f, 1.0f);
	model_xform->SetScale(1.25);
	model_xform->Rotate((float)glfwGetTime() * 0.5, 0.0f, 0.0f);
}

void Model::Draw(std::shared_ptr<Camera>& camera)
{
	ResolveTransforms();
	material->Bind(camera, model_xform);
	mesh->Draw();
}


