#ifndef __GLSHAPES_GLSHAPE_H__
#define __GLSHAPES_GLSHAPE_H__

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

class GLShape
{
    protected:
        QOpenGLShaderProgram* pShader;
        QOpenGLFunctions* pFunctions;

    protected:
        GLShape(QOpenGLFunctions* pFunctions, const QString& vertFilename, const QString& fragFilename);
        ~GLShape();

    public:
        void setAspectRatio(float aspectRatio);

    public:
        virtual void paint(float offsetX, float offsetY, float rotate) = 0;
};
#endif
