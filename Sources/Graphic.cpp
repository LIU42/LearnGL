#include "Graphic.h"

GraphicWidget::GraphicWidget(QWidget* parent): QOpenGLWidget(parent)
{
    format.setVersion(OPENGL_MAJOR_VERSION, OPENGL_MINOR_VERSION);
    format.setSamples(MSAA_SAMPLE);
    format.setProfile(QSurfaceFormat::CoreProfile);
    setFormat(format);
}

GraphicWidget::~GraphicWidget()
{
    makeCurrent();
}

void GraphicWidget::setOpenGLConfig()
{
    glClearColor(CLEAR_COLOR_R, CLEAR_COLOR_G, CLEAR_COLOR_B, CLEAR_COLOR_A);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GraphicWidget::loadShaders()
{
    graphicShader.create();
    graphicShader.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/GraphicVertex.glsl");
    graphicShader.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/GraphicFragment.glsl");
    graphicShader.link();
    textureShader.create();
    textureShader.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Shaders/TextureVertex.glsl");
    textureShader.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Shaders/TextureFragment.glsl");
    textureShader.link();
}

void GraphicWidget::initShapes()
{
    triangle.initShape(this, &graphicShader);
    rectangle.initShape(this, &graphicShader);
    texture.initShape(this, &textureShader);
}

void GraphicWidget::setScreenRatio()
{
    float screenWidth = geometry().width();
    float screenHeight = geometry().height();

    textureShader.bind();
    textureShader.setUniformValue("screenRatio", screenHeight / screenWidth);
    textureShader.release();
    graphicShader.bind();
    graphicShader.setUniformValue("screenRatio", screenHeight / screenWidth);
    graphicShader.release();
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
    setOpenGLConfig();
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
    texture.paintShape(offsetX, offsetY, offsetAngle);
}
