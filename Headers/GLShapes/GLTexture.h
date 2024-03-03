#ifndef __GLSHAPES_GLTEXTURE_H__
#define __GLSHAPES_GLTEXTURE_H__

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>

#include "GLShapes/GLShape.h"

class GLTextureShape : public GLShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
             0.5f,  0.5f,  0.0f,  1.0f,  1.0f,
             0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.0f,  0.0f,  1.0f
        };

    private:
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 4;
        static constexpr int VERTEX_OFFSET = 0;
        static constexpr int VERTEX_STRIDE = 20;

    private:
        static constexpr int TEXTURE_OFFSET = 12;
        static constexpr int TEXTURE_DIMENSION = 2;
        static constexpr int TEXTURE_SAMPLER = 0;

    private:
        static constexpr int INDEX_ARRAY[] = {
            0, 1, 3,
            1, 2, 3
        };

    private:
        static constexpr int INDEX_COUNT = 6;
        static constexpr int POSITION_LAYOUT = 0;
        static constexpr int TEXCROOD_LAYOUT = 1;

    private:
        QOpenGLVertexArrayObject* pVertexArrayObject;
        QOpenGLBuffer* pVertexBufferObject;
        QOpenGLBuffer* pIndexBufferObject;
        QOpenGLTexture* pTextureObject;

    private:
        void createObjects();
        void setTextures();
        void bindObjects();
        void unbindObjects();
        void allocateBuffer();
        void setAttribute();

    public:
        GLTextureShape(QOpenGLFunctions* pFunctions);
        virtual ~GLTextureShape();

    public:
        void paint(float offsetX, float offsetY, float rotate) override;
};
#endif
