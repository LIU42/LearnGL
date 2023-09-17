#include "Shapes/Triangle.h"

TriangleShape::TriangleShape()
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
}

TriangleShape::~TriangleShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
}

void TriangleShape::createObjects()
{
    pVertexArrayObject->create();
    pVertexBufferObject->create();
}

void TriangleShape::bindObjects()
{
    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
}

void TriangleShape::unbindObjects()
{
    pVertexArrayObject->release();
    pVertexBufferObject->release();
}

void TriangleShape::allocateBuffer()
{
    pVertexBufferObject->allocate(VERTEX_ARRAY, VERTEX_SIZE);
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

void TriangleShape::paintShape(float offsetX, float offsetY, float offsetAngle)
{
    pVertexArrayObject->bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("offsetAngle", offsetAngle);
    pFunctions->glDrawArrays(GL_TRIANGLES, VERTEX_OFFSET, VERTEX_COUNT);
    pVertexArrayObject->release();
    pShader->release();
}
