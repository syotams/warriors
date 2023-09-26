#include "Sprite.h"

Sprite::Sprite(Vector2 position, Vector2 dimension, int maxSpeed) : position(position), dimension(dimension), maxSpeed(maxSpeed), speed(maxSpeed)
{
    setWalkDirection(Direction::None, Direction::Right);
};

void Sprite::setWalkDirection(Direction x, Direction y)
{
    if (Direction::None != x)
    {
        walkDirection.x = (float)x;
        walkDirection.y = 0;
    }
    if (Direction::None != y)
    {
        walkDirection.y = (float)y;
        walkDirection.x = 0;
    }
}

void Sprite::moveBy(float x, float y)
{
    setWalkDirection((Direction)x, (Direction)y);
    if (x == 0 && y == 0)
    {
        speed = 0;
    }
    else
    {
        speed = maxSpeed;
    }
    position.x += (int)walkDirection.x * speed;
    position.y += (int)walkDirection.y * speed;
}

void Sprite::moveTo(float x, float y)
{
    position.x = x;
    position.y = y;
}

void Sprite::flipDirection()
{
    walkDirection.x *= -1;
    walkDirection.y *= -1;
    lookDirection.x *= -1;
    lookDirection.y *= -1;
    moveBy(walkDirection.x, walkDirection.y);
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

std::vector<Constrain *> Sprite::getConstrains()
{
    return constrains;
}

Vector2 Sprite::getWalkDirection()
{
    return walkDirection;
}

Vector2 Sprite::getLookDirection()
{
    return lookDirection;
}