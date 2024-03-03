#ifndef __SHAPEOFFSET_H__
#define __SHAPEOFFSET_H__

#include <QtMath>

enum class OffsetDirect
{
    TRANSLATION_UP,
    TRANSLATION_DOWN,
    TRANSLATION_LEFT,
    TRANSLATION_RIGHT,
    ROTATION_LEFT,
    ROTATION_RIGHT,
};

class ShapeOffset
{
    private:
        static constexpr auto TRANSLATION_SPEED = 0.01f;
        static constexpr auto ROTATION_SPEED = 1.0f;
        static constexpr auto ROTATION_ANGLE_MOD = 360;

    public:
        static constexpr int DIRECT_COUNT = 6;

    private:
        float offsetX;
        float offsetY;
        float rotate;

    public:
        ShapeOffset();

    public:
        void update(const bool keyPress[]);

    public:
        float getOffsetX();
        float getOffsetY();
        float getRotate();
};
#endif
