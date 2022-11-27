#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Timer.h"

class Application
{
public:
	void Run();
	Application();
	~Application();
	void Input();
private:
	Window* m_window;
	Renderer* m_renderer;
	Timer* m_timer;
};