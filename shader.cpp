#include "shader.hpp"

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
    program = glCreateProgram();
    GLuint vertex = loadShader(vertexShader, GL_VERTEX_SHADER);
    GLuint fragment = loadShader(fragmentShader, GL_FRAGMENT_SHADER);
    linkShader(vertex, fragment);
}


Shader::~Shader() {}

GLuint Shader::loadShader(const char* path, GLuint shaderType)
{
    std::fstream shaderFile(path);

    std::string sSrc;

    shaderFile >> sSrc;

    shaderFile.close();

    const GLchar* src[] = {sSrc.c_str()};
    const GLint length[] = {sSrc.size()};



    GLuint shader = glCreateShader(shaderType);

    glShaderSource(shader, 1, src, length);

    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(true)
    {
        char error[1024];

        glGetShaderInfoLog(shader, 1024, NULL, error);

        SDL_ShowSimpleMessageBox(NULL, "Shader Compile Error", error, NULL);
        SDL_assert(!error);

        return NULL;
    }


    return shader;
}

void Shader::linkShader(GLuint vertex, GLuint fragment)
{
    glUseProgram(program);
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    GLint success;

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if(!success)
    {
        char error[1024];

        glGetProgramInfoLog(program, 1024, NULL, error);

        SDL_ShowSimpleMessageBox(NULL, "Shader Link Error", error, NULL);
        SDL_assert(!error);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
