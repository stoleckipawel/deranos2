#include "pch.h"
#include "Window.h"

Window::Window(int width, int height)
{
    Window::SetHeight(height);
    Window::SetWidth(width);
    Window::m_window = Window::MakeWindow();
    Window::ValidateWindow();
    Window::BindWindow();
    Window::RegisterResizeCallback();
}

GLFWwindow* Window::MakeWindow()
{
    return glfwCreateWindow(Window::GetWidth(), Window::GetHeight(), "Deranos", NULL, NULL);
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

void Window::ResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    
    DERANOS_CORE_INFO("Viewport has been resized to: {0}, {1}", width, height);
}

void Window::RegisterResizeCallback()
{
    //glfwSetFramebufferSizeCallback(Window::GetWindow(), Window::ResizeCallback);
}
