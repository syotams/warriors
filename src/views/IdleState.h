#pragma once
#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include <stdio.h>
#include "raylib.h"
#include "State.h"

class IdleState : public State
{
private:
    Texture2D *textures;
    Texture2D *leftSidedTextures;

public:
    // IdleState(){};
    IdleState(Texture2D *textures, Texture2D *leftSidedTextures);
    ~IdleState();
    static IdleState *make();
    void draw(Vector2 position, Direction *direction);
};

#endif // IDLESTATE_H_