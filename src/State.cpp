#include "State.h"

State::State(int currentFrame, int framesCounter) : currentFrame(currentFrame), framesCounter(framesCounter) {}

void State::move()
{
    if (framesCounter++ >= 60 / framesPerSecond)
    {
        framesCounter = 0;
        if (currentFrame++ >= 9)
        {
            currentFrame = 0;
        }
    }
}

void State::setFramesPerSecond(int frames)
{
    framesPerSecond = frames;
}

void State::setCurrentFrame(int current)
{
    currentFrame = current;
}

int State::getFramesPerSecond()
{
    return framesPerSecond;
}

int State::getCurrentFrame()
{
    return currentFrame;
}

State::~State() {}