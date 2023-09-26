#pragma once
#ifndef SPRITE_HEADER
#define SPRITE_HEADER

#include <vector>
#include "raylib.h"
#include "constrains/Constrain.h"

class Sprite
{
private:
    Vector2 position;
    Vector2 dimension;
    Vector2 direction;
    int max_speed;
    int speed;
    std::vector<Constrain *> constrains;

    void setDirection(float x, float y);

public:
    virtual void moveBy(int x, int y) = 0;
    virtual void draw() = 0;
    virtual void move() = 0;

    void moveBy(float x, float y);
    void addConstrain(Constrain *constrain);
    void moveTo(float x, float y);
    void flipDirection();
    Vector2 center();
    Rectangle box();
};

#endif