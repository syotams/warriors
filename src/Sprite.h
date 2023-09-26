#pragma once
#ifndef SPRITE_HEADER
#define SPRITE_HEADER

#include <vector>
#include "raylib.h"
#include "constrains/Constrain.h"
#include "Direction.h"

class Sprite
{
private:
    Vector2 position;
    Vector2 dimension;
    Vector2 lookDirection;
    Vector2 walkDirection;
    int maxSpeed;
    int speed;
    std::vector<Constrain *> constrains;

    void setWalkDirection(Direction x, Direction y);

protected:
    Sprite(Vector2 position, Vector2 dimension, int max_speed);

public:
    virtual void moveBy(float x, float y);
    virtual void draw() = 0;
    virtual void move() = 0;

    void addConstrain(Constrain *constrain);
    std::vector<Constrain *> getConstrains();
    Vector2 getWalkDirection();
    Vector2 getLookDirection();
    void moveTo(float x, float y);
    void flipDirection();
    Vector2 center();
    Rectangle box();
};

#endif