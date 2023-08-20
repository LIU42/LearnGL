#ifndef __GRAPHICWIDGET_H__
#define __GRAPHICWIDGET_H__

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QSurfaceFormat>

#include "shape.h"

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
        TriangleShape shape;

    private:
        float offsetX;
        float offsetY;

    private:
        void setClearColor();
        void loadShaders();
        void initShapes();
        void initOffset();

    private:
        void initializeGL();
        void resizeGL(int, int);
        void paintGL();

    public:
        GraphicWidget(QWidget* parent = nullptr);

    public:
        void setOffset(float, float);
};
#endif