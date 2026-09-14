#include "GLLoader.hpp"

GLCreateShaderProc glCreateShader = NULL;
GLShaderSourceProc glShaderSource = NULL;
GLCompileShaderProc glCompileShader = NULL;
GLGetShaderivProc glGetShaderiv = NULL;
GLGetShaderInfoLogProc glGetShaderInfoLog = NULL;
GLDeleteShaderProc glDeleteShader = NULL;

GLCreateProgramProc glCreateProgram = NULL;
GLAttachShaderProc glAttachShader = NULL;
GLLinkProgramProc glLinkProgram = NULL;
GLGetProgramivProc glGetProgramiv = NULL;
GLGetProgramInfoLogProc glGetProgramInfoLog = NULL;
GLDeleteProgramProc glDeleteProgram = NULL;
GLUseProgramProc glUseProgram = NULL;

bool loadOpenGLFunctions()
{
    glCreateShader = reinterpret_cast<GLCreateShaderProc>(
        glfwGetProcAddress("glCreateShader")
    );
    glShaderSource = reinterpret_cast<GLShaderSourceProc>(
        glfwGetProcAddress("glShaderSource")
    );
    glCompileShader = reinterpret_cast<GLCompileShaderProc>(
        glfwGetProcAddress("glCompileShader")
    );
    glGetShaderiv = reinterpret_cast<GLGetShaderivProc>(
        glfwGetProcAddress("glGetShaderiv")
    );
    glGetShaderInfoLog = reinterpret_cast<GLGetShaderInfoLogProc>(
        glfwGetProcAddress("glGetShaderInfoLog")
    );
    glDeleteShader = reinterpret_cast<GLDeleteShaderProc>(
        glfwGetProcAddress("glDeleteShader")
    );

    glCreateProgram = reinterpret_cast<GLCreateProgramProc>(
        glfwGetProcAddress("glCreateProgram")
    );
    glAttachShader = reinterpret_cast<GLAttachShaderProc>(
        glfwGetProcAddress("glAttachShader")
    );
    glLinkProgram = reinterpret_cast<GLLinkProgramProc>(
        glfwGetProcAddress("glLinkProgram")
    );
    glGetProgramiv = reinterpret_cast<GLGetProgramivProc>(
        glfwGetProcAddress("glGetProgramiv")
    );
    glGetProgramInfoLog = reinterpret_cast<GLGetProgramInfoLogProc>(
        glfwGetProcAddress("glGetProgramInfoLog")
    );
    glDeleteProgram = reinterpret_cast<GLDeleteProgramProc>(
        glfwGetProcAddress("glDeleteProgram")
    );
    glUseProgram = reinterpret_cast<GLUseProgramProc>(
        glfwGetProcAddress("glUseProgram")
    );

    return glCreateShader != NULL
        && glShaderSource != NULL
        && glCompileShader != NULL
        && glGetShaderiv != NULL
        && glGetShaderInfoLog != NULL
        && glDeleteShader != NULL
        && glCreateProgram != NULL
        && glAttachShader != NULL
        && glLinkProgram != NULL
        && glGetProgramiv != NULL
        && glGetProgramInfoLog != NULL
        && glDeleteProgram != NULL
        && glUseProgram != NULL;
}