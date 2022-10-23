#pragma once
#include "Window.h"
#include "Renderer.h"

class Application
{
public:
	void Run();
	Application();
	~Application();

	std::shared_ptr<Window> window;
	std::shared_ptr<Renderer> renderer;
private:
		
};