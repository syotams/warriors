#pragma once
#ifndef STATE_HEADER
#define STATE_HEADER
#include "raylib.h"
#include "Direction.h"

class State
{
private:
    int currentFrame;
    int framesCounter;
    int framesPerSecond;

public:
    State(int currentFrame, int framesCounter);
    virtual ~State();
    virtual void move();
    virtual void draw(Vector2 position, Direction *direction) = 0;
    void setFramesPerSecond(int frames);
    void setCurrentFrame(int current);
    int getFramesPerSecond();
    int getCurrentFrame();
};
#endif