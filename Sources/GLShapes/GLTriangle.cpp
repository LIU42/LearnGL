#include "GLShapes/GLTriangle.h"

GLTriangleShape::GLTriangleShape()
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
}

GLTriangleShape::~GLTriangleShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
}

void GLTriangleShape::createObjects()
{
    pVertexArrayObject->create();
    pVertexBufferObject->create();
}

void GLTriangleShape::bindObjects()
{
    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
}

void GLTriangleShape::unbindObjects()
{
    pVertexArrayObject->release();
    pVertexBufferObject->release();
}

void GLTriangleShape::allocateBuffer()
{
    pVertexBufferObject->allocate(VERTEX_ARRAY, VERTEX_SIZE);
}

void GLTriangleShape::setAttribute()
{
    pShader->bind();
    pShader->setAttributeBuffer(POSITION_LAYOUT, GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION);
    pShader->enableAttributeArray(POSITION_LAYOUT);
    pShader->release();
}

void GLTriangleShape::initShape(QOpenGLFunctions* pGLFunctions, QOpenGLShaderProgram* pShader)
{
    this->pGLFunctions = pGLFunctions;
    this->pShader = pShader;

    createObjects();
    bindObjects();
    allocateBuffer();
    setAttribute();
    unbindObjects();
}

void GLTriangleShape::paintShape(float offsetX, float offsetY, float offsetAngle)
{
    pVertexArrayObject->bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("offsetAngle", offsetAngle);
    pGLFunctions->glDrawArrays(GL_TRIANGLES, VERTEX_OFFSET, VERTEX_COUNT);
    pVertexArrayObject->release();
    pShader->release();
}
