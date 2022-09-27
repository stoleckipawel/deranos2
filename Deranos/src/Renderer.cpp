#include "pch.h"
#include "Renderer.h"

void Renderer::ClearBackBuffer(glm::vec3 clear_color = glm::vec3(0.0, 0.0, 0.0))
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Renderloop()
{
	Renderer::ClearBackBuffer(glm::vec3(1.0, 0.0, 1.0));
}

void Renderer::Present()
{	
	//Presents backbuffer to frontbuffer
	// 
	//Check events and swap buffers
	//glfwSwapBuffers(window);
}