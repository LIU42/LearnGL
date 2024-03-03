#include "GLShapes/GLTexture.h"

GLTextureShape::GLTextureShape(QOpenGLFunctions* pFunctions): GLShape(pFunctions, ":/Shaders/Texture.vert", ":/Shaders/Texture.frag")
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    pIndexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    pTextureObject = new QOpenGLTexture(QOpenGLTexture::Target2D);

    pVertexArrayObject->create();
    pVertexBufferObject->create();
    pIndexBufferObject->create();
    pTextureObject->create();

    pTextureObject->setData(QImage(":/Images/texture.png").mirrored());
    pTextureObject->generateMipMaps();
    pTextureObject->setMinMagFilters(QOpenGLTexture::LinearMipMapLinear, QOpenGLTexture::Linear);

    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
    pIndexBufferObject->bind();

    pVertexBufferObject->allocate(VERTEX_ARRAY, sizeof(VERTEX_ARRAY));
    pIndexBufferObject->allocate(INDEX_ARRAY, sizeof(INDEX_ARRAY));

    pShader->bind();
    pShader->setAttributeBuffer(POSITION_LAYOUT, GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION, VERTEX_STRIDE);
    pShader->setAttributeBuffer(TEXCROOD_LAYOUT, GL_FLOAT, TEXTURE_OFFSET, TEXTURE_DIMENSION, VERTEX_STRIDE);
    pShader->enableAttributeArray(POSITION_LAYOUT);
    pShader->enableAttributeArray(TEXCROOD_LAYOUT);
    pShader->release();

    pVertexArrayObject->release();
    pVertexBufferObject->release();
    pIndexBufferObject->release();
}

GLTextureShape::~GLTextureShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
    delete pIndexBufferObject;
    delete pTextureObject;
}

void GLTextureShape::paint(float offsetX, float offsetY, float rotate)
{
    pVertexArrayObject->bind();
    pTextureObject->bind(TEXTURE_SAMPLER);
    pShader->bind();
    pShader->setUniformValue("sampler", TEXTURE_SAMPLER);
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("rotate", rotate);
    pFunctions->glDrawElements(GL_TRIANGLES, INDEX_COUNT, GL_UNSIGNED_INT, NULL);
    pVertexArrayObject->release();
    pShader->release();
}
