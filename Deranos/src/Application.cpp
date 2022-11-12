#include "pch.h"
#include "Application.h"

//#ToDo:
//convert to a singleton

void InitializeGlfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void InitializeGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        DERANOS_CORE_ERROR("Failed to Initialize GLAD!");
    }
}

void Application::OnInput()
{
    if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->GetWindow(), true);

    m_renderer->OnInput();
}

Application::Application()
{
    Log::Init();
    InitializeGlfw();

    m_window = std::make_shared<Window>(1000, 1000, "PRAWIE SUPER ENGINE");

    m_renderer = std::make_shared<Renderer>(m_window);

    InitializeGlad();
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
    m_renderer->PreRender();

    while (!glfwWindowShouldClose(m_window->GetWindow()) && m_window->GetWindow() != NULL)
    {
        OnInput();//Should be callback based

        m_renderer->Renderloop();

        m_renderer->Present();

        glfwPollEvents();
    }
}


