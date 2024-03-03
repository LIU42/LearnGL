#include "Graphic.h"

GraphicWidget::GraphicWidget(QWidget* parent): QOpenGLWidget(parent), pFormat(new QSurfaceFormat())
{
    pFormat->setVersion(OPENGL_MAJOR_VERSION, OPENGL_MINOR_VERSION);
    pFormat->setSamples(MSAA_SAMPLE);
    pFormat->setProfile(QSurfaceFormat::CoreProfile);
    setFormat(*pFormat);
}

GraphicWidget::~GraphicWidget()
{
    makeCurrent();
    delete pTriangle;
    delete pRectangle;
    delete pTexture;
    delete pFormat;
}

void GraphicWidget::setShapeOffset(ShapeOffset* pOffset)
{
    this->pOffset = pOffset;
}

void GraphicWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(CLEAR_COLOR_R, CLEAR_COLOR_G, CLEAR_COLOR_B, CLEAR_COLOR_A);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pTriangle = new GLTriangleShape(this);
    pRectangle = new GLRectangleShape(this);
    pTexture = new GLTextureShape(this);
}

void GraphicWidget::resizeGL(int viewportWidth, int viewportHeight)
{
    float aspectRatio = (float)viewportHeight / (float)viewportWidth;

    pTriangle->setAspectRatio(aspectRatio);
    pRectangle->setAspectRatio(aspectRatio);
    pTexture->setAspectRatio(aspectRatio);
}

void GraphicWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    pTexture->paint(pOffset->getOffsetX(), pOffset->getOffsetY(), pOffset->getRotate());
}
