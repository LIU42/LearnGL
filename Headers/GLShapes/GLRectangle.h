#ifndef __GLSHAPES_GLRECTANGLE_H__
#define __GLSHAPES_GLRECTANGLE_H__

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class GLRectangleShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
             0.4f,  0.3f,  0.0f,
             0.4f, -0.3f,  0.0f,
            -0.4f, -0.3f,  0.0f,
            -0.4f,  0.3f,  0.0f
        };
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 4;
        static constexpr int VERTEX_SIZE = 48;
        static constexpr int VERTEX_OFFSET = 0;

    private:
        static constexpr int INDEX_ARRAY[] = {
            0, 1, 3,
            1, 2, 3
        };
        static constexpr int INDEX_COUNT = 6;
        static constexpr int INDEX_SIZE = 24;

    private:
        static constexpr int POSITION_LAYOUT = 0;

    private:
        QOpenGLShaderProgram* pShader;
        QOpenGLFunctions* pGLFunctions;

    private:
        QOpenGLVertexArrayObject* pVertexArrayObject;
        QOpenGLBuffer* pVertexBufferObject;
        QOpenGLBuffer* pIndexBufferObject;

    private:
        void createObjects();
        void bindObjects();
        void unbindObjects();
        void allocateBuffer();
        void setAttribute();

    public:
        GLRectangleShape();
        ~GLRectangleShape();

    public:
        void initShape(QOpenGLFunctions* pGLFunctions, QOpenGLShaderProgram* pShader);
        void paintShape(float offsetX, float offsetY, float offsetAngle);
};
#endif