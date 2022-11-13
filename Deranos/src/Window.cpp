#include "pch.h"
#include "Window.h"

Window::Window(int height = 1200, int width = 720, std::string name = "")
    : m_window(MakeWindow()), m_width(width), m_height(height), m_name(name)
{
    ValidateWindow();
    BindWindow();
    RegisterResizeCallback();
}

GLFWwindow* Window::MakeWindow()
{
    return glfwCreateWindow(GetWidth(), GetHeight(), GetName().c_str(), NULL, NULL);
}

void Window::BindWindow()
{
    glfwMakeContextCurrent(GetWindow());
}

void Window::ValidateWindow()
{
    if (GetWindow() == NULL)
    {
        DERANOS_CORE_ERROR("GLFW Window Validation Failed!");
    }
}

void Window::ResizeCallback(GLFWwindow* window, int width, int height)
{
    //glViewport(0, 0, width, height);// to be uncommented when proper resize callback is added

    DERANOS_CORE_INFO("Viewport has been resized to: {0}, {1}", width, height);
}

void Window::RegisterResizeCallback()
{
    //Universal wrapper for callback is needed
    glfwSetFramebufferSizeCallback(GetWindow(), ResizeCallback);
}

