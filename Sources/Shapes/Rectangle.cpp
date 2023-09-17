#include "Shapes/Rectangle.h"

RectangleShape::RectangleShape()
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    pIndexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
}

RectangleShape::~RectangleShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
    delete pIndexBufferObject;
}

void RectangleShape::createObjects()
{
    pVertexArrayObject->create();
    pVertexBufferObject->create();
    pIndexBufferObject->create();
}

void RectangleShape::bindObjects()
{
    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
    pIndexBufferObject->bind();
}

void RectangleShape::unbindObjects()
{
    pVertexArrayObject->release();
    pVertexBufferObject->release();
    pIndexBufferObject->release();
}

void RectangleShape::allocateBuffer()
{
    pVertexBufferObject->allocate(VERTEX_ARRAY, VERTEX_SIZE);
    pIndexBufferObject->allocate(INDEX_ARRAY, INDEX_SIZE);
}

void RectangleShape::setAttribute()
{
    pShader->bind();
    pShader->setAttributeBuffer("position", GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION);
    pShader->enableAttributeArray("position");
    pShader->release();
}

void RectangleShape::initShape(QOpenGLFunctions* pFunctions, QOpenGLShaderProgram* pShader)
{
    this->pFunctions = pFunctions;
    this->pShader = pShader;

    createObjects();
    bindObjects();
    allocateBuffer();
    setAttribute();
    unbindObjects();
}

void RectangleShape::paintShape(float offsetX, float offsetY, float offsetAngle)
{
    pVertexArrayObject->bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("offsetAngle", offsetAngle);
    pFunctions->glDrawElements(GL_TRIANGLES, INDEX_COUNT, GL_UNSIGNED_INT, NULL);
    pVertexArrayObject->release();
    pShader->release();
}