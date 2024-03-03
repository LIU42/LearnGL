#ifndef __GLSHAPES_GLRECTANGLE_H__
#define __GLSHAPES_GLRECTANGLE_H__

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>

#include "GLShapes/GLShape.h"

class GLRectangleShape : public GLShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
             0.4f,  0.3f,  0.0f,
             0.4f, -0.3f,  0.0f,
            -0.4f, -0.3f,  0.0f,
            -0.4f,  0.3f,  0.0f
        };

    private:
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 4;
        static constexpr int VERTEX_OFFSET = 0;

    private:
        static constexpr int INDEX_ARRAY[] = {
            0, 1, 3,
            1, 2, 3
        };

    private:
        static constexpr int INDEX_COUNT = 6;
        static constexpr int POSITION_LAYOUT = 0;

    private:
        QOpenGLVertexArrayObject* pVertexArrayObject;
        QOpenGLBuffer* pVertexBufferObject;
        QOpenGLBuffer* pIndexBufferObject;

    public:
        GLRectangleShape(QOpenGLFunctions* pFunctions);
        virtual ~GLRectangleShape();

    public:
        void paint(float offsetX, float offsetY, float rotate) override;
};
#endif