#include "Sprite.h"

void Sprite::setDirection(float x, float y)
{
    if (0 != x)
    {
        direction.x = x;
        direction.y = 0;
    }
    if (0 != y)
    {
        direction.y = y;
        direction.x = 0;
    }
}

void Sprite::moveBy(float x, float y)
{
    setDirection(x, y);
    if (x == 0 && y == 0)
    {
        speed = 0;
    }
    else
    {
        speed = max_speed;
    }
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Sprite::moveTo(float x, float y)
{
    position.x = x;
    position.y = y;
}

void Sprite::flipDirection()
{
    direction.x *= -1;
    direction.y *= -1;
    moveBy(direction.x, direction.y);
}

Vector2 Sprite::center()
{
    return {position.x + dimension.x / 2,
            position.y + dimension.y / 2};
}

Rectangle Sprite::box()
{
    return {position.x, position.y, dimension.x, dimension.y};
}

void Sprite::addConstrain(Constrain *constrain)
{
    constrains.push_back(constrain);
}