#pragma once

#include "Log.h"

class Window
{
public:
	Window::Window(int height, int width, const std::string& name);
	inline int GetWidth() { return Window::m_width; };
	inline void SetHeight(int height) { Window::m_height = height; };

	inline const std::string& GetName() { return Window::m_name; };

	inline int GetHeight() { return Window::m_height; };
	inline void SetWidth(int width) { Window::m_width = width; };

	inline GLFWwindow* GetWindow() { return Window::m_window; }
private:
	GLFWwindow* MakeWindow();
	void BindWindow();
	void ValidateWindow();
	void ResizeCallback(GLFWwindow* window, int width, int height);
	void RegisterResizeCallback();

	int m_width;
	int m_height;
	const std::string& m_name;
	GLFWwindow* m_window;
};



