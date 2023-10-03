#include "FollowerConstrain.h"

FollowerConstrain::~FollowerConstrain()
{
    std::cout << "*** in FollowerConstrain::~FollowerConstrain\n";
}

void FollowerConstrain::apply()
{
    Vector2 position = chaser->getPosition();
    Vector2 chasedPosition = chased->getPosition();

    float yDiff = chasedPosition.y - position.y;
    float xDiff = chasedPosition.x - position.x;

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
    Direction go[2];

    if (x > 0)
    {
        if (int(position.y) % grid_size > 0.0f)
        {
            go[1] = direction.y > 0 ? Direction::Down : Direction::Up;
            go[0] = Direction::None;
        }
        else
        {
            go[0] = Direction::Right;
        }
    }
    else if (x < 0)
    {
        if (int(position.y) % grid_size > 0.0f)
        {
            go[1] = direction.y > 0 ? Direction::Down : Direction::Up;
            go[0] = Direction::None;
        }
        else
        {
            go[0] = Direction::Left;
        }
    }
    else if (y < 0)
    {
        if (int(position.x) % grid_size > 0.0f)
        {
            go[0] = direction.x > 0 ? Direction::Right : Direction::Left;
            go[1] = Direction::None;
        }
        else
        {
            go[1] = Direction::Up;
        }
    }
    else if (y > 0)
    {
        if (int(position.x) % grid_size > 0.0f)
        {
            go[0] = direction.x > 0 ? Direction::Right : Direction::Left;
            go[1] = Direction::None;
        }
        else
        {
            go[1] = Direction::Down;
        }
    }
    chaser->moveBy(go[0], go[1]);
}