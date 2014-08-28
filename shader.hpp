#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <fstream>

class Shader
{
public:
    Shader(const char* vertexShader, const char* fragmentShader);
    ~Shader();

    GLuint getProgram();

private:
    GLuint program;
    inline GLuint loadShader(const char* path, GLuint shaderType);
    inline void linkShader(GLuint vertex, GLuint fragment);

};


#endif // SHADER_HPP
