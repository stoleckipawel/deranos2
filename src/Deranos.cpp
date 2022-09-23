#include "Deranos.h"

namespace Deranos
{
    void initialize_glfw()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);

        DERANOS_CORE_INFO("Viewport has been resized to: {0}, {1}", width, height);
    }

    void initialize_window()
    {
        //GLFW Window
        Deranos::window = glfwCreateWindow(Deranos::window_width, Deranos::window_height, "Deranos", NULL, NULL);
        if (Deranos::window == NULL)//Check whether window has been created
        {
            DERANOS_CORE_ERROR("Failed to Initialize GLFW Window!");
        }
        glfwMakeContextCurrent(Deranos::window);

        //Register Resize function callback for the window
        glfwSetFramebufferSizeCallback(Deranos::window, Deranos::framebuffer_size_callback);
    }

    void initialize_glad()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            DERANOS_CORE_ERROR("Failed to Initialize GLAD!");
        }
    }

    void initialize()
    {
        Deranos::Log::Init();
        Deranos::initialize_glfw();
        Deranos::initialize_window();
        Deranos::initialize_glad();
    }

    void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void ClearBackBuffer(glm::vec3 clear_color = glm::vec3(0.0, 0.0, 0.0) ) 
    {
        glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderloop()
    {
        Deranos::ClearBackBuffer(glm::vec3(1.0, 0.0, 0.0));
    }

    void update()
    {
        while (!glfwWindowShouldClose(window) && window != NULL)
        {   
            //Input
            processInput(window);

            Deranos::renderloop();

            //Check events and swap buffers
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void terminate()
    {
        glfwTerminate();
    }
}

int main()
{
    Deranos::initialize();
    Deranos::update();
    Deranos::terminate();
}