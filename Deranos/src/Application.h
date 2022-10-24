#pragma once
#include "Window.h"
#include "Renderer.h"

class Application
{
public:
	void Run();
	Application();
	~Application();
	void OnInput();
private:
	std::shared_ptr<Window> m_window;
	std::shared_ptr<Renderer> m_renderer;
};