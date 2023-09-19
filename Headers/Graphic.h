#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QSurfaceFormat>

#include "GLShapes/GLTriangle.h"
#include "GLShapes/GLRectangle.h"

class GraphicWidget : public QOpenGLWidget, QOpenGLFunctions
{
    Q_OBJECT

    private:
        static constexpr int OPENGL_MAJOR_VERSION = 3;
        static constexpr int OPENGL_MINOR_VERSION = 3;
        static constexpr int MSAA_SAMPLE = 16;

    private:
        static constexpr float CLEAR_COLOR_R = 0.2f;
        static constexpr float CLEAR_COLOR_G = 0.3f;
        static constexpr float CLEAR_COLOR_B = 0.3f;
        static constexpr float CLEAR_COLOR_A = 1.0f;

    private:
        QOpenGLShaderProgram shader;
        QSurfaceFormat format;

    private:
        GLTriangleShape triangle;
        GLRectangleShape rectangle;

    private:
        float offsetX;
        float offsetY;
        float offsetAngle;

    private:
        void setClearColor();
        void loadShaders();
        void initShapes();
        void initOffset();
        void setScreenRatio();

    private:
        void initializeGL();
        void resizeGL(int, int);
        void paintGL();

    public:
        GraphicWidget(QWidget* parent = nullptr);

    public:
        void setOffset(float, float, float);
};
#endif