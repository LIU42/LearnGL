#ifndef __GLSHAPES_GLTEXTURE_H__
#define __GLSHAPES_GLTEXTURE_H__

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>

class GLTextureShape
{
    private:
        static constexpr float VERTEX_ARRAY[] = {
             0.5f,  0.5f,  0.0f,  1.0f,  1.0f,
             0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.0f,  0.0f,  1.0f
        };
        static constexpr int VERTEX_DIMENSION = 3;
        static constexpr int VERTEX_COUNT = 4;
        static constexpr int VERTEX_SIZE = 80;
        static constexpr int VERTEX_OFFSET = 0;
        static constexpr int VERTEX_STRIDE = 20;

    private:
        static constexpr int INDEX_ARRAY[] = {
            0, 1, 3,
            1, 2, 3
        };
        static constexpr int INDEX_COUNT = 6;
        static constexpr int INDEX_SIZE = 24;

    private:
        static constexpr int POSITION_LAYOUT = 0;
        static constexpr int TEXCROOD_LAYOUT = 1;

    private:
        static constexpr int TEXTURE_OFFSET = 12;
        static constexpr int TEXTURE_DIMENSION = 2;
        static constexpr int TEXTURE_SAMPLER = 0;

    private:
        QOpenGLShaderProgram* pShader;
        QOpenGLFunctions* pGLFunctions;

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
        GLTextureShape();
        ~GLTextureShape();

    public:
        void initShape(QOpenGLFunctions* pGLFunctions, QOpenGLShaderProgram* pShader);
        void paintShape(float offsetX, float offsetY, float offsetAngle);
};
#endif
