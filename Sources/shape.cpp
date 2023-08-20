#include "shape.h"

void TriangleShape::createObjects()
{
    vertexArrayObject.create();
    vertexBufferObject.create();
}

void TriangleShape::bindObjects()
{
    vertexArrayObject.bind();
    vertexBufferObject.bind();
}

void TriangleShape::unbindObjects()
{
    vertexArrayObject.release();
    vertexBufferObject.release();
}

void TriangleShape::allocateBuffer()
{
    vertexBufferObject.allocate(VERTEX_ARRAY, VERTEX_SIZE);
}

void TriangleShape::setAttribute()
{
    pShader->bind();
    pShader->setAttributeBuffer("position", GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION);
    pShader->enableAttributeArray("position");
    pShader->release();
}

void TriangleShape::initShape(QOpenGLFunctions* pFunctions, QOpenGLShaderProgram* pShader)
{
    this->pFunctions = pFunctions;
    this->pShader = pShader;

    createObjects();
    bindObjects();
    allocateBuffer();
    setAttribute();
    unbindObjects();
}

void TriangleShape::paintShape(float offsetX, float offsetY)
{
    vertexArrayObject.bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pFunctions->glDrawArrays(GL_TRIANGLES, VERTEX_OFFSET, VERTEX_COUNT);
    vertexArrayObject.release();
    pShader->release();
}
