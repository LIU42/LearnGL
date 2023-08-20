#include "graphic.h"

GraphicWidget::GraphicWidget(QWidget* parent): QOpenGLWidget(parent)
{
    format.setVersion(OPENGL_MAJOR_VERSION, OPENGL_MINOR_VERSION);
    format.setSamples(MSAA_SAMPLE);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);
}

void GraphicWidget::setClearColor()
{
    glClearColor(CLEAR_COLOR_R, CLEAR_COLOR_G, CLEAR_COLOR_B, CLEAR_COLOR_A);
}

void GraphicWidget::loadShaders()
{
    shader.create();
    shader.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/vertex.glsl");
    shader.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/fragment.glsl");
    shader.link();
}

void GraphicWidget::initShapes()
{
    shape.initShape(this, &shader);
}

void GraphicWidget::setOffset(float offsetX, float offsetY)
{
    this->offsetX = offsetX;
    this->offsetY = offsetY;
}

void GraphicWidget::initializeGL()
{
    initializeOpenGLFunctions();
    setClearColor();
    loadShaders();
    initShapes();
}

void GraphicWidget::resizeGL(int screenWidth, int screenHeight)
{
    glViewport(0, 0, screenWidth, screenHeight);
}

void GraphicWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    shape.paintShape(offsetX, offsetY);
}
