#include "ScreenConstrain.h"

void ScreenConstrain::apply()
{
    Vector2 position = element->getPosition();

    if (position.x < 0)
    {
        position.x = 0;
    }
    else if (position.x + TEXTURE_SIZE > screenWidth)
    {
        position.x = screenWidth - TEXTURE_SIZE;
    }
    if (position.y < 0)
    {
        position.y = 0;
    }
    else if (position.y + TEXTURE_SIZE > screenHeight)
    {
        position.y = screenHeight - TEXTURE_SIZE;
    }
    element->moveTo(position.x, position.y);
}