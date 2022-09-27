#pragma once

#include <iostream>
#include <string>

#include <glad.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Log.h"

#include "Renderer.h"

#include "Window.h"

class Application
{
public:
	void Run();
	Application();
	~Application();

	Window* window;
private:
		
};