#include "pch.h"
#include "Material.h"
#include "Camera.h"

Material::Material(const char* vertex_shader_path, const char* pixel_shader_path, const char* texture_path)
{
	texture = std::make_shared<Texture>(texture_path, true);
	shader = std::make_shared<Shader>(vertex_shader_path, pixel_shader_path);
}


void Material::Bind(std::shared_ptr<Camera>& camera, std::shared_ptr<Transform>& model_xform)
{
	texture->Bind();
	shader->Bind(camera, model_xform);
}