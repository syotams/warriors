#include "Sprite.h"

Sprite::Sprite(Vector2 position, Vector2 dimension, int maxSpeed) : position(position), dimension(dimension), maxSpeed(maxSpeed), speed(maxSpeed)
{
    setWalkDirection(Direction::None, Direction::None);
}

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

void Sprite::moveBy(float x, float y)
{
    walkDirection.x = x;
    walkDirection.y = y;
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
    moveBy(walkDirection.x, walkDirection.y);
}

Vector2 Sprite::getPosition()
{
    return position;
}

Vector2 Sprite::center()
{
    return {position.x + dimension.x / 2,
            position.y + dimension.y / 2};
}

Rectangle Sprite::rectacngle()
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

std::vector<Constrain *> Sprite::getAbilities()
{
    return abilities;
}

Vector2 Sprite::getWalkDirection()
{
    return walkDirection;
}

void Sprite::setSpeed(int speed)
{
    if (speed >= 0)
    {
        this->speed = speed;
    }
}

int Sprite::getSpeed()
{
    return speed;
}

void Sprite::setMaxSpeed(int speed)
{
    if (speed >= 0)
    {
        this->maxSpeed = speed;
    }
}

int Sprite::getMaxSpeed()
{
    return maxSpeed;
}

Sprite::~Sprite()
{
    log("Sprite::~Sprite() destructing constrains");
    for (auto &constrain : constrains)
    {
        delete constrain;
    }
}