#include "vertexArrayObject.hpp"

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &id);
}

void VertexArrayObject::use()
{
    glBindVertexArray(id);
}

void VertexArrayObject::clear()
{
    glBindVertexArray(0);
}
