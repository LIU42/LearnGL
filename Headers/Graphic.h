#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QSurfaceFormat>

#include "GLShapes/GLTriangle.h"
#include "GLShapes/GLRectangle.h"
#include "GLShapes/GLTexture.h"

class GraphicWidget : public QOpenGLWidget, QOpenGLFunctions
{
    Q_OBJECT

    private:
        static constexpr int OPENGL_MAJOR_VERSION = 4;
        static constexpr int OPENGL_MINOR_VERSION = 5;
        static constexpr int MSAA_SAMPLE = 4;

    private:
        static constexpr float CLEAR_COLOR_R = 0.2f;
        static constexpr float CLEAR_COLOR_G = 0.3f;
        static constexpr float CLEAR_COLOR_B = 0.3f;
        static constexpr float CLEAR_COLOR_A = 1.0f;

    private:
        QOpenGLShaderProgram graphicShader;
        QOpenGLShaderProgram textureShader;
        QSurfaceFormat format;

    private:
        GLTriangleShape triangle;
        GLRectangleShape rectangle;
        GLTextureShape texture;

    private:
        float offsetX;
        float offsetY;
        float offsetAngle;

    private:
        void setOpenGLConfig();
        void loadShaders();
        void initShapes();
        void initOffset();
        void setScreenRatio();

    private:
        void initializeGL();
        void resizeGL(int screenWidth, int screenHeight);
        void paintGL();

    public:
        GraphicWidget(QWidget* parent = nullptr);
        ~GraphicWidget();

    public:
        void setOffset(float offsetX, float offsetY, float offsetAngle);
};
#endif