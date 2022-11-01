#pragma once

#include <Mesh.h>
#include <Material.h>
#include <Transform.h>
#include <Camera.h>

class Model
{
public:
	Model(const char* vertex_shader_path, const char* pixel_shader_path, const char* texture_path);
	void Draw(std::shared_ptr<Camera>& camera);

	std::shared_ptr<Material> material;
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Transform> model_xform;
private:
	void ResolveTransforms();
};

