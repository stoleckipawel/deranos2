#include "pch.h"
#include "Application.h"

void Application::Input()
{
    //#To do convert to event dispatcher
    if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->GetWindow(), true);

    m_renderer->OnInput();
    glfwPollEvents();
}

Application::Application()
{
    Log::Init();

    m_timer = new Timer();
    m_window = new Window(1200, 1200, "PRAWIE SUPER ENGINE");
    m_renderer = new Renderer(m_window, m_timer);
    DERANOS_CORE_INFO("App::Initialized");
}

Application::~Application()
{
    delete m_renderer;
    delete m_window;
    delete m_timer;
    DERANOS_CORE_INFO("App::Destroyed");
}

void Application::Run()
{
    m_renderer->PreRender();//Builds assets

    while (!glfwWindowShouldClose(m_window->GetWindow()) && m_window->GetWindow() != nullptr)
    {
        Input();//#To do convert to event dispatcher

        m_renderer->Renderloop();

        m_renderer->Present();

        m_timer->Update();
    }
}

int main()
{
    Application app;
    app.Run();
}


