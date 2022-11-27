#include "pch.h"
#include "Scene.h"

Scene::Scene(Camera* camera)
	: m_camera(camera)
{
	DERANOS_CORE_INFO("Renderer::Scene::INITIALIZED");
}

void Scene::Draw()
{
	for each (auto model in models)
	{
		model->Draw(*m_camera);
	}
}