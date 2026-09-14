#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

App::App(const std::string& modelPath) : _modelPath(modelPath), _window(NULL) 
{
    
}

App::~App()
{
    if (_window != NULL)
        glfwDestroyWindow(_window);

    glfwTerminate();
}

bool App::init()
{
    if (!glfwInit()) {
        std::cerr << "Error: GLFW initialization failed" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(1280, 720, "SCOP", NULL, NULL);

    if (_window == NULL) {
        std::cerr << "Error: window creation failed" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);

    return true;
}

void App::run()
{
    while (!glfwWindowShouldClose(_window)) 
    {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(_window, GLFW_TRUE);

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}