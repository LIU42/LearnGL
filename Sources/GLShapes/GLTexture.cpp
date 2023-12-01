#include "GLShapes/GLTexture.h"

GLTextureShape::GLTextureShape()
{
    pVertexArrayObject = new QOpenGLVertexArrayObject();
    pVertexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    pIndexBufferObject = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    pTextureObject = new QOpenGLTexture(QOpenGLTexture::Target2D);
}

GLTextureShape::~GLTextureShape()
{
    delete pVertexArrayObject;
    delete pVertexBufferObject;
    delete pIndexBufferObject;
    delete pTextureObject;
}

void GLTextureShape::createObjects()
{
    pVertexArrayObject->create();
    pVertexBufferObject->create();
    pIndexBufferObject->create();
    pTextureObject->create();
}

void GLTextureShape::setTextures()
{
    pTextureObject->setData(QImage(":/Images/texture.png").mirrored());
    pTextureObject->generateMipMaps();
    pTextureObject->setMinMagFilters(QOpenGLTexture::LinearMipMapLinear, QOpenGLTexture::Linear);
}

void GLTextureShape::bindObjects()
{
    pVertexArrayObject->bind();
    pVertexBufferObject->bind();
    pIndexBufferObject->bind();
}

void GLTextureShape::unbindObjects()
{
    pVertexArrayObject->release();
    pVertexBufferObject->release();
    pIndexBufferObject->release();
}

void GLTextureShape::allocateBuffer()
{
    pVertexBufferObject->allocate(VERTEX_ARRAY, VERTEX_SIZE);
    pIndexBufferObject->allocate(INDEX_ARRAY, INDEX_SIZE);
}

void GLTextureShape::setAttribute()
{
    pShader->bind();
    pShader->setAttributeBuffer(POSITION_LAYOUT, GL_FLOAT, VERTEX_OFFSET, VERTEX_DIMENSION, VERTEX_STRIDE);
    pShader->setAttributeBuffer(TEXCROOD_LAYOUT, GL_FLOAT, TEXTURE_OFFSET, TEXTURE_DIMENSION, VERTEX_STRIDE);
    pShader->enableAttributeArray(POSITION_LAYOUT);
    pShader->enableAttributeArray(TEXCROOD_LAYOUT);
    pShader->release();
}

void GLTextureShape::initShape(QOpenGLFunctions* pGLFunctions, QOpenGLShaderProgram* pShader)
{
    this->pGLFunctions = pGLFunctions;
    this->pShader = pShader;

    createObjects();
    setTextures();
    bindObjects();
    allocateBuffer();
    setAttribute();
    unbindObjects();
}

void GLTextureShape::paintShape(float offsetX, float offsetY, float offsetAngle)
{
    pVertexArrayObject->bind();
    pTextureObject->bind(TEXTURE_SAMPLER);
    pShader->bind();
    pShader->setUniformValue("textureSampler", TEXTURE_SAMPLER);
    pShader->setUniformValue("offsetX", offsetX);
    pShader->setUniformValue("offsetY", offsetY);
    pShader->setUniformValue("offsetAngle", offsetAngle);
    pGLFunctions->glDrawElements(GL_TRIANGLES, INDEX_COUNT, GL_UNSIGNED_INT, NULL);
    pVertexArrayObject->release();
    pShader->release();
}
