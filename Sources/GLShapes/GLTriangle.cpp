#include "GLShapes/GLTriangle.h"

GLTriangleShape::GLTriangleShape(QOpenGLFunctions* pFunctions): GLShape(pFunctions, ":/Shaders/Triangle.vert", ":/Shaders/Triangle.frag")
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);

    pVertexArrayObject->create();
    pVertexBufferObject->create();

    pVertexArrayObject->bind();
    pVertexBufferObject->bind();

    pVertexBufferObject->allocate(VERTEX_ARRAY, sizeof(VERTEX_ARRAY));
    pShader->bind();
    pShader->setAttributeBuffer(POSITION_LAYOUT, GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION);
    pShader->enableAttributeArray(POSITION_LAYOUT);
    pShader->release();

    pVertexArrayObject->release();
    pVertexBufferObject->release();
}

GLTriangleShape::~GLTriangleShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
}

void GLTriangleShape::paint(float offsetX, float offsetY, float rotate)
{
    pVertexArrayObject->bind();
    pShader->bind();
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("rotate", rotate);
    pFunctions->glDrawArrays(GL_TRIANGLES, VERTEX_OFFSET, VERTEX_COUNT);
    pVertexArrayObject->release();
    pShader->release();
}
