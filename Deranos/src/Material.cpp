#include "pch.h"
#include "Material.h"
#include "Camera.h"


Material::Material()
	: m_shader(std::make_shared<Shader>("shaders/simple.vs", "shaders/simple.ps")),
	m_texture(std::make_shared<Texture>("resources/models/backpack/diffuse.jpg", TextureTypes::Diffuse()))
{
}

void Material::Bind(Camera& camera, Transform& model_xform)
{
	m_shader->Bind(*m_texture, camera, model_xform);
}


