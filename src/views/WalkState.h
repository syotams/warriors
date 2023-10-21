#pragma once
#ifndef WALKSTATE_H_
#define WALKSTATE_H_

#include <stdio.h>
#include "raylib.h"
#include "State.h"
#include "../textures_container.h"

class WalkState : public State
{
private:
    Texture2D *rTextures;
    Texture2D *lTextures;

public:
    WalkState(Texture2D *rTextures, Texture2D *lTextures);
    ~WalkState();
    static WalkState *make(TexturesContainer *contianer);
    void draw(Vector2 position, Direction *direction) override;
};

#endif // WALKSTATE_H_