#pragma once
#include "Window.h"
#include "Renderer.h"

class Application
{
public:
	void Run();
	Application();
	~Application();
	void Input();
private:
	void InitializeGlad();
	void InitializeGlfw();
	std::shared_ptr<Window> m_window;
	std::shared_ptr<Renderer> m_renderer;
};