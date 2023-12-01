#ifndef __GLSHAPES_GLTRIANGLE_H__
#define __GLSHAPES_GLTRIANGLE_H__

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class GLTriangleShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
            -0.4f, -0.3f,  0.0f,
             0.4f, -0.3f,  0.0f,
             0.0f,  0.3f,  0.0f
        };
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 3;
        static constexpr int VERTEX_SIZE = 36;
        static constexpr int VERTEX_OFFSET = 0;

    private:
        static constexpr int POSITION_LAYOUT = 0;

    private:
        QOpenGLShaderProgram* pShader;
        QOpenGLFunctions* pGLFunctions;

    private:
        QOpenGLVertexArrayObject* pVertexArrayObject;
        QOpenGLBuffer* pVertexBufferObject;

    private:
        void createObjects();
        void bindObjects();
        void unbindObjects();
        void allocateBuffer();
        void setAttribute();

    public:
        GLTriangleShape();
        ~GLTriangleShape();

    public:
        void initShape(QOpenGLFunctions* pGLFunctions, QOpenGLShaderProgram* pShader);
        void paintShape(float offsetX, float offsetY, float offsetAngle);
};
#endif
