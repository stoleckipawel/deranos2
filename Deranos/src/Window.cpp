#include "pch.h"
#include "Window.h"

Window::Window(int height = 1200, int width = 720, const std::string& name = "Deranos")
    : m_width(width), m_height(height), m_name(name)
{
    Window::m_window = Window::MakeWindow();
    Window::ValidateWindow();
    Window::BindWindow();
    Window::RegisterResizeCallback();
}

GLFWwindow* Window::MakeWindow()
{
    return glfwCreateWindow(Window::GetWidth(), Window::GetHeight(), Window::GetName().c_str(), NULL, NULL);
}

void Window::BindWindow()
{
    glfwMakeContextCurrent(Window::GetWindow());
}

void Window::ValidateWindow()
{
    if (Window::GetWindow() == NULL)
    {
        DERANOS_CORE_ERROR("GLFW Window Validation Failed!");
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    DERANOS_CORE_INFO("Viewport has been resized to: {0}, {1}", width, height);
}

void Window::RegisterResizeCallback()
{
    glfwSetFramebufferSizeCallback(Window::GetWindow(), framebuffer_size_callback);
}

