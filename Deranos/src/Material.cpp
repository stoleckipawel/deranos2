#include "pch.h"
#include "Material.h"
#include "Camera.h"

Material::Material()
{
	//Attach dummy texture & dummy shader at initialization
	m_shader = std::make_shared<Shader>("shaders/simple.vs", "shaders/simple.ps");
	m_texture_0 = std::make_shared<Texture>("resources/textures/container.jpg", true);
}

void Material::Bind(std::shared_ptr<Camera>& camera, std::shared_ptr<Transform>& model_xform)
{
	m_texture_0->Bind();
	m_shader->Bind(camera, model_xform);
}

void Material::AttachShader(std::shared_ptr<Shader>& shader)
{
	m_shader = shader;
}

void Material::AttachTexture(std::shared_ptr<Texture>& texture)
{
	m_texture_0 = texture;
}
