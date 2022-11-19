#include "pch.h"
#include "Application.h"

int main()
{
    //Application loop

    Application* app = new Application();
    app->Run();
    delete app;
}