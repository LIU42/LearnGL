#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class TriangleShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
            -0.3f, -0.3f, 0.0f,
             0.3f, -0.3f, 0.0f,
             0.0f,  0.3f, 0.0f
        };
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 3;
        static constexpr int VERTEX_SIZE = 36;
        static constexpr int VERTEX_OFFSET = 0;

    private:
        QOpenGLShaderProgram* pShader;
        QOpenGLFunctions* pFunctions;

    private:
        QOpenGLVertexArrayObject vertexArrayObject;
        QOpenGLBuffer vertexBufferObject;

    private:
        void createObjects();
        void bindObjects();
        void unbindObjects();
        void allocateBuffer();
        void setAttribute();

    public:
        void initShape(QOpenGLFunctions*, QOpenGLShaderProgram*);
        void paintShape(float, float);
};
#endif