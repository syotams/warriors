#include "State.h"

State::State(int currentFrame, int framesCounter) : currentFrame(currentFrame), framesCounter(framesCounter) {}

void State::draw(Vector2 position, Direction *direction)
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

void State::reset()
{
    currentFrame = 0;
    framesCounter = 0;
}

bool State::isCompleted()
{
    return currentFrame >= 9;
}

State::~State()
{
    log("State::~State() nothing to destruct");
}