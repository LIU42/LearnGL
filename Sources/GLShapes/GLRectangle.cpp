#include "GLShapes/GLRectangle.h"

GLRectangleShape::GLRectangleShape(QOpenGLFunctions* pFuncions): GLShape(pFuncions, ":/Shaders/Rectangle.vert", ":/Shaders/Rectangle.frag")
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    pIndexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);

    pVertexArrayObject->create();
    pVertexBufferObject->create();
    pIndexBufferObject->create();

    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
    pIndexBufferObject->bind();

    pVertexBufferObject->allocate(VERTEX_ARRAY, sizeof(VERTEX_ARRAY));
    pIndexBufferObject->allocate(INDEX_ARRAY, sizeof(INDEX_ARRAY));

    pShader->bind();
    pShader->setAttributeBuffer(POSITION_LAYOUT, GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION);
    pShader->enableAttributeArray(POSITION_LAYOUT);
    pShader->release();

    pVertexArrayObject->release();
    pVertexBufferObject->release();
    pIndexBufferObject->release();
}

GLRectangleShape::~GLRectangleShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
    delete pIndexBufferObject;
}

void GLRectangleShape::paint(float offsetX, float offsetY, float rotate)
{
    pVertexArrayObject->bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("rotate", rotate);
    pFunctions->glDrawElements(GL_TRIANGLES, INDEX_COUNT, GL_UNSIGNED_INT, NULL);
    pVertexArrayObject->release();
    pShader->release();
}