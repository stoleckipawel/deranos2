#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Timer.h"

class Application
{
public:
	void Run();
	Application();
	void Input();
private:
	std::shared_ptr<Window> m_window;
	std::shared_ptr<Renderer> m_renderer;
	std::shared_ptr<Timer> m_timer;
};