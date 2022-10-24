#pragma once
#include <Window.h>

class Input
{
public:
	static bool IsKeyPressed(int keyCode, std::shared_ptr<Window> window);

	static bool IsMouseButtonPressed(int button, std::shared_ptr<Window> window);

	static std::pair<float, float> GetMousePosition(std::shared_ptr<Window> window);
	static float GetMouseX(std::shared_ptr<Window> window);
	static float GetMouseY(std::shared_ptr<Window> window);
};

