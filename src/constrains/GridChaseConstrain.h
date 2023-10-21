#pragma once
#ifndef FOLLOWERCONSTRAIN_H_
#define FOLLOWERCONSTRAIN_H_

#include <iostream>
#include <cmath>
#include "../models/Sprite.h"
#include "Constrain.h"

class GridChaseConstrain : public Constrain
{
    Sprite *chaser;
    Sprite *chased;
    int grid_size;

public:
    GridChaseConstrain(Sprite *chaser, Sprite *chased, int grid_size) : chaser(chaser), chased(chased), grid_size(grid_size){};
    virtual ~GridChaseConstrain();
    void apply();
};

#endif