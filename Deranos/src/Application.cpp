#include "pch.h"
#include "Application.h"

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

    window = std::make_shared<Window>(900, 900, "PRAWIE SUPER ENGINE");
    renderer = std::make_shared<Renderer>();
    InitializeGlad();
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
    renderer->PreRender();

    while (!glfwWindowShouldClose(window->GetWindow()) && window->GetWindow() != NULL)
    {
        //Input
        ProcessInput(window->GetWindow());

        renderer->Render();
        renderer->Present();

        //Check events and swap buffers
        glfwSwapBuffers(window->GetWindow());
        glfwPollEvents();
    }
}


