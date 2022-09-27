#include "pch.h"
#include "Application.h"
#include "Renderer.h"

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

void ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

Application::Application()
{
    Log::Init();
    InitializeGlfw();

    Application::window = new Window(800, 600, "PRAWIE SUPER ENGINE");
    InitializeGlad();
}

Application::~Application()
{
    glfwTerminate();
    delete Application::window;
}

void Application::Run()
{
    while (!glfwWindowShouldClose(Application::window->GetWindow()) && Application::window->GetWindow() != NULL)
    {
        //Input
        ProcessInput(Application::window->GetWindow());

        Renderer::Renderloop();
        Renderer::Present();

        //Check events and swap buffers
        glfwSwapBuffers(Application::window->GetWindow());
        glfwPollEvents();
    }
}


