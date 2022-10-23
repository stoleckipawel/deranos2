#include "pch.h"
#include "Input.h"
#include "Application.h"
/*
bool Input::IsKeyPressed(int keyCode)
{
	auto window = Application::window->GetWindow();

	auto state = glfwGetKey(window, keyCode);

	return state & (GLFW_PRESS || GLFW_REPEAT);
}

bool Input::IsMouseButtonPressed(int button)
{
	auto window = Application::window->GetWindow();

	auto state = glfwGetMouseButton(window, button);

	return state & GLFW_PRESS;
}

std::pair<float, float> Input::GetMousePosition()
{
	auto window = Application::window->GetWindow();

	double posX, posY;
	glfwGetCursorPos(window, &posX, &posY);
	return { (float)posX, (float)posY };
}

float Input::GetMouseX()
{
	auto [x, y] = GetMousePosition();
	return x;
}

float Input::GetMouseY()
{
	auto [x, y] = GetMousePosition();
	return y;
}
*/

