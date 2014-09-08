/** @file shader.hpp
    @brief Shader Header File */

#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <fstream>


/**
 *  @brief The Shader class handles using and creating OpenGL shader porograms
 *
 *  This class is simply a wrapper for some gl* shader functions.
 *  it also Allows for easy organization of shaders.
 */
class Shader
{
public:

    /**
     * @brief Shader constructor
     * @param vertexShader
     * @param fragmentShader
     */
    Shader(const char* vertexShader, const char* fragmentShader);
    ~Shader();

    /** Returns the GLuint ID of the shader program */
    GLuint getProgram();

    /** Wrapper for the glUseProgram function */
    void use();

    /** calls glUseProgram(0) */
    static void clear();

private:
    GLuint program;
    inline GLuint loadShader(const char* path, GLuint shaderType);
    inline void linkShader(GLuint vertex, GLuint fragment);
};


#endif // SHADER_HPP
