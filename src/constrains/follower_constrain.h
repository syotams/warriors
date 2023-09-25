#pragma once
#ifndef DOG_CHASE_GRID_HEADER
#define DOG_CHASE_GRID_HEADER

#include <iostream>
#include <cmath>
#include "../sprite.h"
#include "constrain.h"

class FollowerConstrain : public Constrain
{
    Sprite *chaser;
    Sprite *chased;
    int grid_size;

public:
    FollowerConstrain(Sprite *chaser, Sprite *chased, int grid_size) : chaser(chaser), chased(chased), grid_size(grid_size){};
    virtual ~FollowerConstrain();
    void apply();
};
#endif