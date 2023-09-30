#pragma once
#ifndef ATTACKSTATE_H_
#define ATTACKSTATE_H_

#include <stdio.h>
#include "raylib.h"
#include "State.h"
#include "../textures_container.h"

class AttackState : public State
{
private:
    Texture2D *rTextures;
    Texture2D *lTextures;

public:
    AttackState(Texture2D *rTextures, Texture2D *leftSideTextures);
    ~AttackState();
    static AttackState *make(TexturesContainer *container);
    void draw(Vector2 position, Direction *direction);
};

#endif // ATTACKSTATE_H_