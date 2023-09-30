#pragma once
#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include <stdio.h>
#include "raylib.h"
#include "State.h"
#include "../textures_container.h"

class IdleState : public State
{
private:
    Texture2D *rTextures;
    Texture2D *lTextures;

public:
    IdleState(Texture2D *rTextures, Texture2D *lTextures);
    ~IdleState();
    static IdleState *make(TexturesContainer *container);
    void draw(Vector2 position, Direction *direction);
};

#endif // IDLESTATE_H_