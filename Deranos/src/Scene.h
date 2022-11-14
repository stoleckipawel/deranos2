#pragma once
#include <camera.h>
#include <Model.h>

class Scene
{
public:
	Scene(Camera& camera);
	void Draw();

	std::vector<std::shared_ptr<Model>> models; //Is vector of shared pointer a bad idea?
private:
	Camera& m_camera;
};

