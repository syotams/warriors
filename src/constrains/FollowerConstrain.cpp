#include "FollowerConstrain.h"

FollowerConstrain::~FollowerConstrain()
{
    std::cout << "*** in FollowerConstrain::~FollowerConstrain\n";
}

void FollowerConstrain::apply()
{
    Vector2 chaserPosition = chaser->getPosition();
    Vector2 chasedPosition = chased->getPosition();

    float yDiff = chasedPosition.y - chaserPosition.y;
    float xDiff = chasedPosition.x - chaserPosition.x;

    double distance = sqrt(yDiff * yDiff + xDiff * xDiff);

    float x = xDiff / distance;
    float y = yDiff / distance;

    if (abs(x) >= abs(y))
    {
        y = 0;
        x = x > 0 ? 1 : -1;
    }
    else
    {
        x = 0;
        y = y > 0 ? 1 : -1;
    }

    Vector2 direction = chaser->getWalkDirection();

    if (x > 0)
    {
        if (int(chaserPosition.y) % grid_size > 0.0f)
        {
            y = direction.y;
            x = 0;
        }
        else
        {
            x = 1;
        }
    }
    else if (x < 0)
    {
        if (int(chaserPosition.y) % grid_size > 0.0f)
        {
            y = direction.y;
            x = 0;
        }
        else
        {
            x = -1;
        }
    }
    else if (y < 0)
    {
        if (int(chaserPosition.x) % grid_size > 0.0f)
        {
            x = direction.x;
            y = 0;
        }
        else
        {
            y = -1;
        }
    }
    else if (y > 0)
    {
        if (int(chaserPosition.x) % grid_size > 0.0f)
        {
            x = direction.x;
            y = 0;
        }
        else
        {
            y = 1;
        }
    }
    chaser->moveBy(x, y);
}