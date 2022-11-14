#pragma once
#include "Shader.h"
#include "Texture.h"


class Material
{
public:
	Material();
	void Bind(Camera& camera, Transform& model_xform);
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture> texture;
private:

};


