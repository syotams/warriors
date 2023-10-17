#pragma once
#ifndef SPRITE_HEADER
#define SPRITE_HEADER

#include <vector>
#include "raylib.h"
#include "../constrains/Constrain.h"
#include "../Direction.h"
#include "../helpers/Log.h"

class Sprite
{
private:
    Vector2 dimension;
    Vector2 walkDirection;
    int maxSpeed;
    int speed;
    std::vector<Constrain *> constrains;
    std::vector<Constrain *> abilities;

    void setWalkDirection(Direction x, Direction y);

protected:
    Vector2 position;
    Sprite(Vector2 position, Vector2 dimension, int max_speed);

public:
    virtual void moveBy(Direction x, Direction y);
    virtual void moveBy(float x, float y);
    virtual void draw() = 0;
    virtual void move() = 0;

    void moveTo(float x, float y);
    void flipDirection();

    void addConstrain(Constrain *constrain);
    std::vector<Constrain *> getConstrains();
    std::vector<Constrain *> getAbilities();
    Vector2 getWalkDirection();
    Vector2 getPosition();
    Vector2 center();
    Rectangle box();
    void setSpeed(int speed);
    int getSpeed();
    void setMaxSpeed(int speed);
    int getMaxSpeed();

    virtual ~Sprite();
};

#endif