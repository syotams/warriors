#pragma once
#ifndef ATTACKSTATE_H_
#define ATTACKSTATE_H_

#include <stdio.h>
#include "raylib.h"
#include "State.h"

class AttackState : public State
{
private:
    Texture2D *rightSidedTextures;
    Texture2D *leftSidedTextures;

public:
    AttackState(Texture2D *rightSidedTextures, Texture2D *leftSideTextures);
    ~AttackState();
    static AttackState *make();
    void draw(Vector2 position, Direction *direction);
};

#endif // ATTACKSTATE_H_