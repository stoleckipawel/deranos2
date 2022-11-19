#include "pch.h"
#include "Application.h"

//#ToDo:
//convert to a singleton

void MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    /*
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
        type, severity, message);
    */
}

void Application::InitializeGlfw()//#To do: hide under abstraction
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::InitializeGlad()//#To do: hide under abstraction
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        DERANOS_CORE_ERROR("Failed to Initialize GLAD!");
    }
}

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

    InitializeGlfw();

    m_window = std::make_shared<Window>(1200, 1200, "PRAWIE SUPER ENGINE");

    m_renderer = std::make_shared<Renderer>(*m_window);

    InitializeGlad();

    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    //glDebugMessageCallback(MessageCallback, 0);
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
    m_renderer->PreRender();//Builds assets



    while (!glfwWindowShouldClose(m_window->GetWindow()) && m_window->GetWindow() != nullptr)
    {
        Input();////#To do convert to event dispatcher

        m_renderer->Renderloop();//rendering in general

        m_renderer->Present();//swap front & back bufer
    }
}


