/** @file vertexArrayObject.hpp
 *  @brief vertexArrayObject header */
#ifndef VERTEXARRAYOBJECT_HPP
#define VERTEXARRAYOBJECT_HPP
#include <GL/glew.h>
#include <SDL2/SDL.h>

/**
 * @brief The VertexArrayObject class is a very
 * 	      small wrapper over the VAO functions
 *        in OpenGL
 */
class VertexArrayObject
{
public:
    /** creates the VAO and stores its GLuint ID */
    VertexArrayObject();

    /** calls glBindArray */
    void use();

    /** calls glBindArray(0) */
    static void clear();

private:
    GLuint id;
};

#endif // VERTEXARRAYOBJECT_HPP
