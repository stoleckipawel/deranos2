#pragma once

#include "Log.h"

class Window
{
public:
	Window(int height, int width, std::string name);
	~Window();

	inline int GetWidth() const { return m_width; };
	inline void SetHeight(int height) { m_height = height; };

	inline const std::string& GetName() const { return m_name; };

	inline int GetHeight() const { return m_height; };
	inline void SetWidth(int width) { m_width = width; };

	inline GLFWwindow* GetWindow() const { return m_window; }
private:
	GLFWwindow* MakeWindow();
	void BindWindow();
	void ValidateWindow();
	void RegisterResizeCallback();
	static void ResizeCallback(GLFWwindow* window, int width, int height);
	void InitializeGlfw();

	int m_width;
	int m_height;
	std::string m_name;
	GLFWwindow* m_window;
};



