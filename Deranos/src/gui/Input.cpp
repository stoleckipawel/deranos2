#include "pch.h"
#include "Input.h"

bool Input::IsKeyPressed(int keyCode, const Window& window)
{
	auto state = glfwGetKey(window.GetWindow(), keyCode);
	return state & (GLFW_PRESS || GLFW_REPEAT);
}

bool Input::IsMouseButtonPressed(int button, const Window& window)
{
	auto state = glfwGetMouseButton(window.GetWindow(), button);
	return state & GLFW_PRESS;
}

std::pair<float, float> Input::GetMousePosition(const Window& window)
{
	double posX, posY;
	glfwGetCursorPos(window.GetWindow(), &posX, &posY);
	return { (float)posX, (float)posY };
}

float Input::GetMouseX(const Window& window)
{
	auto [x, y] = GetMousePosition(window);
	return x;
}

float Input::GetMouseY(const Window& window)
{
	auto [x, y] = GetMousePosition(window);
	return y;
}


