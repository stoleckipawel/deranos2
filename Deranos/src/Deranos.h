#pragma once

#include <iostream>
#include <string>

#include <glad.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Log.h"

namespace Deranos 
{
	int window_width = 800;
	int window_height = 600;

	GLFWwindow* window;
}