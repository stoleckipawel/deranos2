#include "pch.h"
#include "Application.h"

//#ToDo:
//convert to a singleton

void Application::Input()
{
    if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window->GetWindow(), true);

    m_renderer->OnInput();

    glfwPollEvents();
}

Application::Application()
{
    Log::Init();

    m_timer = std::make_shared<Timer>();

    m_window = std::make_shared<Window>(1200, 1200, "PRAWIE SUPER ENGINE");

    m_renderer = std::make_shared<Renderer>(*m_window, *m_timer);

    DERANOS_CORE_INFO("App::INITIALIZED");
}

void Application::Run()
{
    m_renderer->PreRender();//Builds assets

    while (!glfwWindowShouldClose(m_window->GetWindow()) && m_window->GetWindow() != nullptr)
    {
        Input();////#To do convert to event dispatcher

        m_renderer->Renderloop();//rendering in general

        m_renderer->Present();//swap front & back bufer

        m_timer->Update();
    }
}


