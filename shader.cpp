#include "shader.hpp"

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
    program = glCreateProgram();
    loadShader(vertexShader, GL_VERTEX_SHADER);
    loadShader(fragmentShader, GL_FRAGMENT_SHADER);
    compileShader();
}


Shader::~Shader() {}

GLuint Shader::loadShader(const char* path, GLuint shaderType)
{
    std::fstream shaderFile(path);

    std::string sSrc;

    shaderFile >> sSrc;

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

void Shader::compileShader(GLuint vertex, GLuint fragment)
{
    glUseProgram(program);
    glLinkShader(vertex);
    glLinkShader(fragment);


}
