#include "pch.h"
#include "Material.h"
#include "Camera.h"


Material::Material()
	: shader(std::make_shared<Shader>("shaders/simple.vs", "shaders/simple.ps")),
	texture(std::make_shared<Texture>("resources/textures/default_texture.png", TextureTypes::Diffuse()))
{
}

void Material::Bind(Camera& camera, Transform& model_xform)
{
	shader->Bind(*texture, camera, model_xform);
}


