#pragma once
#include <camera.h>
#include <Model.h>

class Scene
{
	//Scene probably should input Entity not explicitly models
public:
	Scene(Camera& camera);
	void Draw();


	std::vector<std::shared_ptr<Model>> models;
private:
	Camera& m_camera;
};

