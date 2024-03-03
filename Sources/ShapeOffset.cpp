#include "ShapeOffset.h"

ShapeOffset::ShapeOffset()
{
    offsetX = 0;
    offsetY = 0;
    rotate = 0;
}

void ShapeOffset::update(const bool keyPress[])
{
    if (keyPress[(int)OffsetDirect::TRANSLATION_UP])
    {
        offsetY += TRANSLATION_SPEED;
    }
    if (keyPress[(int)OffsetDirect::TRANSLATION_DOWN])
    {
        offsetY -= TRANSLATION_SPEED;
    }
    if (keyPress[(int)OffsetDirect::TRANSLATION_LEFT])
    {
        offsetX -= TRANSLATION_SPEED;
    }
    if (keyPress[(int)OffsetDirect::TRANSLATION_RIGHT])
    {
        offsetX += TRANSLATION_SPEED;
    }
    if (keyPress[(int)OffsetDirect::ROTATION_LEFT])
    {
        rotate = fmod(rotate - ROTATION_SPEED, ROTATION_ANGLE_MOD);
    }
    if (keyPress[(int)OffsetDirect::ROTATION_RIGHT])
    {
        rotate = fmod(rotate + ROTATION_SPEED, ROTATION_ANGLE_MOD);
    }
}

float ShapeOffset::getOffsetX()
{
    return offsetX;
}

float ShapeOffset::getOffsetY()
{
    return offsetY;
}

float ShapeOffset::getRotate()
{
    return rotate;
}
