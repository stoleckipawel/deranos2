#include "pch.h"
#include "Window.h"

Window::Window(int height = 1200, int width = 1200, std::string name = "")
    : m_width(width), m_height(height), m_name(name)
{
    InitializeGlfw();
    m_window = MakeWindow();
    ValidateWindow();
    BindWindow();
    RegisterResizeCallback();

    DERANOS_CORE_INFO("Window::Initialized");
}

Window::~Window()
{
    glfwTerminate();

    DERANOS_CORE_INFO("Window::Destroyed");
}

void Window::InitializeGlfw()//#To do: hide under abstraction
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
    DERANOS_CORE_INFO("Glfw::Initialized");
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
    if (GetWindow() == nullptr)
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


bool Input::IsKeyPressed(int keyCode, Window* window)
{
    auto state = glfwGetKey(window->GetWindow(), keyCode);
    return state & (GLFW_PRESS || GLFW_REPEAT);
}

bool Input::IsMouseButtonPressed(int button, Window* window)
{
    auto state = glfwGetMouseButton(window->GetWindow(), button);
    return state & GLFW_PRESS;
}

std::pair<float, float> Input::GetMousePosition(Window* window)
{
    double posX, posY;
    glfwGetCursorPos(window->GetWindow(), &posX, &posY);
    return { (float)posX, (float)posY };
}

float Input::GetMouseX(Window* window)
{
    auto [x, y] = GetMousePosition(window);
    return x;
}

float Input::GetMouseY(Window* window)
{
    auto [x, y] = GetMousePosition(window);
    return y;
}
