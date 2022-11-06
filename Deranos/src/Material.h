#pragma once
#include "Shader.h"
#include "Texture.h"

class Material
{
public:
	Material();
	void Bind(std::shared_ptr<Camera>& camera, std::shared_ptr<Transform>& model_xform);
	
	void AttachShader(std::shared_ptr<Shader>& shader);
	void AttachTexture(std::shared_ptr<Texture>& texture);
private:
	std::shared_ptr<Shader> m_shader;
	std::shared_ptr<Texture> m_texture_0;
};


