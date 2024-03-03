#ifndef __GLSHAPES_GLTRIANGLE_H__
#define __GLSHAPES_GLTRIANGLE_H__

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>

#include "GLShapes/GLShape.h"

class GLTriangleShape : public GLShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
            -0.4f, -0.3f,  0.0f,
             0.4f, -0.3f,  0.0f,
             0.0f,  0.3f,  0.0f
        };

    private:
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 3;
        static constexpr int VERTEX_OFFSET = 0;
        static constexpr int POSITION_LAYOUT = 0;

    private:
        QOpenGLVertexArrayObject* pVertexArrayObject;
        QOpenGLBuffer* pVertexBufferObject;

    public:
        GLTriangleShape(QOpenGLFunctions* pFunctions);
        virtual ~GLTriangleShape();

    public:
        void paint(float offsetX, float offsetY, float rotate) override;
};
#endif
