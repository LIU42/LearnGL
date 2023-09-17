#include "Graphic.h"

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
    triangle.initShape(this, &shader);
    rectangle.initShape(this, &shader);
}

void GraphicWidget::setScreenRatio()
{
    float screenWidth = geometry().width();
    float screenHeight = geometry().height();

    shader.bind();
    shader.setUniformValue("screenRatio", screenHeight / screenWidth);
    shader.release();
}

void GraphicWidget::setOffset(float offsetX, float offsetY, float offsetAngle)
{
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->offsetAngle = offsetAngle;
}

void GraphicWidget::initializeGL()
{
    initializeOpenGLFunctions();
    setClearColor();
    loadShaders();
    initShapes();
    setScreenRatio();
}

void GraphicWidget::resizeGL(int screenWidth, int screenHeight)
{
    glViewport(0, 0, screenWidth, screenHeight);
    setScreenRatio();
}

void GraphicWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle.paintShape(offsetX, offsetY, offsetAngle);
}
