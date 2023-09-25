#include "screen_constrain.h"

void ScreenConstrain::apply()
{
    Vector2 position = element->getPosition();
    int screen_size = NUMBER_OF_TILES * TILE_SIZE;

    if (position.x < 0)
    {
        position.x = 0;
    }
    else if (position.x + TILE_SIZE > screen_size)
    {
        position.x = screen_size - TILE_SIZE;
    }
    if (position.y < 0)
    {
        position.y = 0;
    }
    else if (position.y + TILE_SIZE > screen_size)
    {
        position.y = screen_size - TILE_SIZE;
    }
    element->moveTo(position.x, position.y);
}