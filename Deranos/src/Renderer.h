#pragma once

#include <glad.h>
#include <glfw3.h>
#include <glm/glm.hpp>

class Renderer
{
public:
	static void Renderloop();
	static void Present();
private:
	static void ClearBackBuffer(glm::vec3 clear_color);
};



