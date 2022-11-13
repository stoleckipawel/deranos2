#pragma once
#include "Shader.h"
#include "Texture.h"


class Material
{
public:
	Material();
	void Bind(Camera& camera, Transform& model_xform);
private:
	std::shared_ptr<Shader> m_shader;
	std::shared_ptr<Texture> m_texture;
};


