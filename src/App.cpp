#include "App.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

static void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height);
}

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
    glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);

    int framebufferWidth;
    int framebufferHeight;
    
    glfwGetFramebufferSize(_window, &framebufferWidth, &framebufferHeight);
    glViewport(0, 0, framebufferWidth, framebufferHeight);
    glClearColor(0.08f, 0.10f, 0.14f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glCreateShader(GL_VERTEX_SHADER);

    return true;
}

void App::run()
{
    while (!glfwWindowShouldClose(_window)) 
    {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(_window, GLFW_TRUE);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}