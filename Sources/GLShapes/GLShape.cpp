#include "GLShapes/GLShape.h"

GLShape::GLShape(QOpenGLFunctions* pFunctions, const QString& vertFilename, const QString& fragFilename)
{
    this->pFunctions = pFunctions;
    this->pShader = new QOpenGLShaderProgram();
    this->pShader->create();
    this->pShader->addShaderFromSourceFile(QOpenGLShader::Vertex, vertFilename);
    this->pShader->addShaderFromSourceFile(QOpenGLShader::Fragment, fragFilename);
    this->pShader->link();
}

GLShape::~GLShape()
{
    delete pShader;
}

void GLShape::setAspectRatio(float aspectRatio)
{
    pShader->bind();
    pShader->setUniformValue("aspectRatio", aspectRatio);
    pShader->release();
}