#pragma once
#include "Shader.h"
#include "Texture.h"

class Material
{
public:
	Material(const char* vertex_shader_path, const char* pixel_shader_path, const char* texture_path);
	void Bind(std::shared_ptr<Camera>& camera, std::shared_ptr<Transform>& model_xform);
	std::shared_ptr<Texture> texture;
	std::shared_ptr<Shader> shader;
private:

};


