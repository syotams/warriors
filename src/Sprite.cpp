#include "Sprite.h"

Sprite::Sprite(Vector2 position, Vector2 dimension, int maxSpeed) : position(position), dimension(dimension), maxSpeed(maxSpeed), speed(maxSpeed)
{
    setWalkDirection(Direction::None, Direction::Right);
};

void Sprite::setWalkDirection(Direction x, Direction y)
{
    walkDirection.x = 0;
    walkDirection.y = 0;
    if (Direction::None != x)
    {
        walkDirection.x = x == Direction::Right ? 1 : -1;
    }
    if (Direction::None != y)
    {
        walkDirection.y = y == Direction::Down ? 1 : -1;
    }
}

void Sprite::moveBy(Direction x, Direction y)
{
    setWalkDirection(x, y);
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
    moveBy((Direction)walkDirection.x, (Direction)walkDirection.y);
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
