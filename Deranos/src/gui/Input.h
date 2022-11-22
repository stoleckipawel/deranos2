#pragma once
#include <Window.h>

class Input
{
public:
	static bool IsKeyPressed(int keyCode, const Window& window);

	static bool IsMouseButtonPressed(int button, const Window& window);

	static std::pair<float, float> GetMousePosition(const Window& window);
	static float GetMouseX(const Window& window);
	static float GetMouseY(const Window& window);
};

