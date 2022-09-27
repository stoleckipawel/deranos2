#pragma once

#include "Log.h"

class Window
{
public:
	Window::Window(int height, int width);
	inline int GetWidth() { return Window::m_width; };
	inline void SetHeight(int height) { Window::m_height = height; };

	inline int GetHeight() { return Window::m_height; };
	inline void SetWidth(int width) { Window::m_width = width; };

	inline GLFWwindow* GetWindow() { return Window::m_window; }
private:
	GLFWwindow* MakeWindow();
	void BindWindow();
	void ValidateWindow();
	void ResizeCallback(GLFWwindow* window, int width, int height);
	void RegisterResizeCallback();

	int m_width = 800;
	int m_height = 600;
	GLFWwindow* m_window;
};



