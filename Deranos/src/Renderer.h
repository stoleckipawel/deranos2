#pragma once



class Renderer
{
public:
	static void Renderloop();
	static void Present();
private:
	static void ClearBackBuffer(glm::vec3 clear_color);
};



