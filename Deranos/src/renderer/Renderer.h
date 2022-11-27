#pragma once
#include <Camera.h>

#include <Model.h>
#include <Mesh.h>
#include <Texture.h>
#include "Shader.h"
#include <Transform.h>
#include <Window.h>
#include <Gui.h>
#include "Material.h"
#include "Scene.h"


class Renderer
{
public:
	Renderer(Window& window, Timer& timer);
	void PreRender();
	void Renderloop();
	void Present();
	void OnInput();
private:
	void CopyToBackBuffer(std::shared_ptr<Texture>);
	void ClearZbuffer();
	void ClearStencil();
	void SetPolyFillMode();
	void DrawGui();
	void InitializeGlad();

	void SetRenderTargetView();

	Window& m_window;
	Timer& m_timer;

	bool m_show_wireframe;

	std::shared_ptr<Camera> m_camera;
	std::shared_ptr<Gui> m_gui;// to be stored elsewhere
	std::shared_ptr<Scene> m_scene;
	
	//To be moved somewhere else
	std::shared_ptr<Model> m_backpack;
	std::shared_ptr<Model> m_cube;
	
	std::shared_ptr<Mesh> m_quad;
	std::shared_ptr<Material> m_copy_material;
};


/*
//Singleton impl
//Lifetime of a class -> lifetime of the application
class Renderer
{
public:
	Renderer(const Renderer&) = delete;//prevents from coping

	static Renderer& Get()
	{
		static Renderer instace;
		return instace;
	}

	static float Test() { return Get().TestImpl(); }
private:
	float TestImpl();
	Renderer() {}//Singleton so we dont want to exposure constructor
};
*/



