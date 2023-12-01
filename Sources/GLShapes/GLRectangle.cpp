#include "GLShapes/GLRectangle.h"

GLRectangleShape::GLRectangleShape()
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    pIndexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
}

GLRectangleShape::~GLRectangleShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
    delete pIndexBufferObject;
}

void GLRectangleShape::createObjects()
{
    pVertexArrayObject->create();
    pVertexBufferObject->create();
    pIndexBufferObject->create();
}

void GLRectangleShape::bindObjects()
{
    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
    pIndexBufferObject->bind();
}

void GLRectangleShape::unbindObjects()
{
    pVertexArrayObject->release();
    pVertexBufferObject->release();
    pIndexBufferObject->release();
}

void GLRectangleShape::allocateBuffer()
{
    pVertexBufferObject->allocate(VERTEX_ARRAY, VERTEX_SIZE);
    pIndexBufferObject->allocate(INDEX_ARRAY, INDEX_SIZE);
}

void GLRectangleShape::setAttribute()
{
    pShader->bind();
    pShader->setAttributeBuffer(POSITION_LAYOUT, GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION);
    pShader->enableAttributeArray(POSITION_LAYOUT);
    pShader->release();
}

void GLRectangleShape::initShape(QOpenGLFunctions* pGLFunctions, QOpenGLShaderProgram* pShader)
{
    this->pGLFunctions = pGLFunctions;
    this->pShader = pShader;

    createObjects();
    bindObjects();
    allocateBuffer();
    setAttribute();
    unbindObjects();
}

void GLRectangleShape::paintShape(float offsetX, float offsetY, float offsetAngle)
{
    pVertexArrayObject->bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("offsetAngle", offsetAngle);
    pGLFunctions->glDrawElements(GL_TRIANGLES, INDEX_COUNT, GL_UNSIGNED_INT, NULL);
    pVertexArrayObject->release();
    pShader->release();
}