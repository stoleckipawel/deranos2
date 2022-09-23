#include <iostream>
#include <string>

#include <glad.h>
#include <glfw3.h>



int window_width = 800;
int window_height = 600;

GLFWwindow* window;

namespace deranos
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

        std::cout << "Viewport has been resized to: " << width << "," << height << std::endl;
    }

    void initialize_window()
    {
        //GLFW Window
        window = glfwCreateWindow(window_width, window_height, "Deranos", NULL, NULL);
        if (window == NULL)//Check whether window has been created
        {
            std::cout << "Failed to create GLFW window" << std::endl;
        }
        glfwMakeContextCurrent(window);

        //Register Resize function callback for the window
        glfwSetFramebufferSizeCallback(window, deranos::framebuffer_size_callback);
    }

    void initialize_glad()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
    }

    void initialize()
    {
        deranos::initialize_glfw();
        deranos::initialize_window();
        deranos::initialize_glad();
    }

    void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void ClearBackBuffer()//TO DO GLM 
    {
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderloop()
    {
        deranos::ClearBackBuffer();
    }

    void update()
    {
        while (!glfwWindowShouldClose(window) && window != NULL)
        {   
            //Input
            processInput(window);

            deranos::renderloop();

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
    deranos::initialize();
    deranos::update();
    deranos::terminate();
}