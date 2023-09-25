#include "grid_constrain.h"

GridConstrain::~GridConstrain()
{
    std::cout << "*** in GridConstrain::~GridConstrain" << std::endl;
}

void GridConstrain::apply()
{
    int x = 0, y = 0;
    Vector2 position = player->getPosition();
    Vector2 direction = player->getDirection();

    if (IsKeyDown(KEY_RIGHT))
    {
        if (int(position.y) % grid_size > 0.0f)
        {
            y = direction.y;
        }
        else
        {
            x = 1;
        }
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        if (int(position.y) % grid_size > 0.0f)
        {
            y = direction.y;
        }
        else
        {
            x = -1;
        }
    }
    else if (IsKeyDown(KEY_UP))
    {
        if (int(position.x) % grid_size > 0.0f)
        {
            x = direction.x;
        }
        else
        {
            y = -1;
        }
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        if (int(position.x) % grid_size > 0.0f)
        {
            x = direction.x;
        }
        else
        {
            y = 1;
        }
    }
    player->moveBy(x, y);
}