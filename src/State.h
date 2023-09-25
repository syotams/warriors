#pragma once
#ifndef STATE_HEADER
#define STATE_HEADER
#include "raylib.h"

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
    virtual void draw(Vector2 position, int direction) = 0;
    void setFramesPerSecond(int frames);
    void setCurrentFrame(int current);
    int getFramesPerSecond();
    int getCurrentFrame();
};
#endif