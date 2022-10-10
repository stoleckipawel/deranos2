#pragma once



class Renderer
{
public:
	static void PreRender();
	static void Render();
	static void Present();
private:
	static void ClearBackBuffer(glm::vec3 clear_color);
};



