#include "ShaderProgram.hpp"
#include "GLLoader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

ShaderProgram::ShaderProgram()
    : _id(0)
{
}

ShaderProgram::~ShaderProgram()
{
    if (_id != 0)
        glDeleteProgram(_id);
}

std::string ShaderProgram::readFile(const std::string& path) const
{
    std::ifstream file(path.c_str());
    std::stringstream buffer;

    if (!file.is_open())
    {
        std::cerr << "Error: cannot open shader file: "
                  << path << std::endl;
        return "";
    }

    buffer << file.rdbuf();
    return buffer.str();
}

bool ShaderProgram::compileShader(
    unsigned int shader,
    const std::string& source,
    const std::string& label
) const
{
    const char *sourcePointer = source.c_str();
    GLint success;
    GLint logLength;

    glShaderSource(shader, 1, &sourcePointer, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (success == GL_TRUE)
        return true;

    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

    std::vector<char> log(logLength);

    glGetShaderInfoLog(
        shader,
        logLength,
        NULL,
        &log[0]
    );

    std::cerr << "Error: " << label
              << " shader compilation failed:" << std::endl;
    std::cerr << &log[0] << std::endl;

    return false;
}

bool ShaderProgram::linkProgram(unsigned int program) const
{
    GLint success;
    GLint logLength;

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (success == GL_TRUE)
        return true;

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

    std::vector<char> log(logLength);

    glGetProgramInfoLog(
        program,
        logLength,
        NULL,
        &log[0]
    );

    std::cerr << "Error: shader program linking failed:"
              << std::endl;
    std::cerr << &log[0] << std::endl;

    return false;
}

bool ShaderProgram::load(
    const std::string& vertexPath,
    const std::string& fragmentPath
)
{
    std::string vertexSource = readFile(vertexPath);
    std::string fragmentSource = readFile(fragmentPath);

    if (vertexSource.empty() || fragmentSource.empty())
        return false;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    if (vertexShader == 0 || fragmentShader == 0)
    {
        std::cerr << "Error: OpenGL could not create shaders."
                  << std::endl;

        if (vertexShader != 0)
            glDeleteShader(vertexShader);

        if (fragmentShader != 0)
            glDeleteShader(fragmentShader);

        return false;
    }

    if (!compileShader(vertexShader, vertexSource, "vertex"))
    {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return false;
    }

    if (!compileShader(fragmentShader, fragmentSource, "fragment"))
    {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return false;
    }

    GLuint program = glCreateProgram();

    if (program == 0)
    {
        std::cerr << "Error: OpenGL could not create shader program."
                  << std::endl;

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return false;
    }

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    if (!linkProgram(program))
    {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glDeleteProgram(program);
        return false;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    if (_id != 0)
        glDeleteProgram(_id);

    _id = program;

    return true;
}

void ShaderProgram::use() const
{
    glUseProgram(_id);
}