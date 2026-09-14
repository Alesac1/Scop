#ifndef GL_LOADER_HPP
# define GL_LOADER_HPP

# include <GLFW/glfw3.h>

typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef char GLchar;
typedef unsigned int GLenum;
typedef unsigned char GLboolean;

typedef GLuint (*GLCreateShaderProc)(GLenum type);
typedef void (*GLShaderSourceProc)(
    GLuint shader,
    GLsizei count,
    const GLchar *const* string,
    const GLint *length
);
typedef void (*GLCompileShaderProc)(GLuint shader);
typedef void (*GLGetShaderivProc)(
    GLuint shader,
    GLenum pname,
    GLint *params
);
typedef void (*GLGetShaderInfoLogProc)(
    GLuint shader,
    GLsizei maxLength,
    GLsizei *length,
    GLchar *infoLog
);
typedef void (*GLDeleteShaderProc)(GLuint shader);

typedef GLuint (*GLCreateProgramProc)(void);
typedef void (*GLAttachShaderProc)(GLuint program, GLuint shader);
typedef void (*GLLinkProgramProc)(GLuint program);
typedef void (*GLGetProgramivProc)(
    GLuint program,
    GLenum pname,
    GLint *params
);
typedef void (*GLGetProgramInfoLogProc)(
    GLuint program,
    GLsizei maxLength,
    GLsizei *length,
    GLchar *infoLog
);
typedef void (*GLDeleteProgramProc)(GLuint program);
typedef void (*GLUseProgramProc)(GLuint program);

extern GLCreateShaderProc glCreateShader;
extern GLShaderSourceProc glShaderSource;
extern GLCompileShaderProc glCompileShader;
extern GLGetShaderivProc glGetShaderiv;
extern GLGetShaderInfoLogProc glGetShaderInfoLog;
extern GLDeleteShaderProc glDeleteShader;

extern GLCreateProgramProc glCreateProgram;
extern GLAttachShaderProc glAttachShader;
extern GLLinkProgramProc glLinkProgram;
extern GLGetProgramivProc glGetProgramiv;
extern GLGetProgramInfoLogProc glGetProgramInfoLog;
extern GLDeleteProgramProc glDeleteProgram;
extern GLUseProgramProc glUseProgram;

bool loadOpenGLFunctions();

#endif