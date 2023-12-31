#pragma once
#ifndef SIMPLE_HADER
#define SIMPLE_HADER

#include "raylib.h"
#include "../sprite.h"
#include "constrain.h"

class SimpleConstrain : public Constrain
{
    Sprite *player;

public:
    SimpleConstrain(Sprite *player) : player(player){};
    ~SimpleConstrain();
    void apply();
};
#endif