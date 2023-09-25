#pragma once
#ifndef GRID_CONSTRAIN_HADER
#define GRID_CONSTRAIN_HADER

#include <stdlib.h>
#include "raylib.h"
#include "../sprite.h"
#include "constrain.h"

class GridConstrain : public Constrain
{
    Sprite *player;
    int grid_size;

public:
    GridConstrain(Sprite *player, int grid_size) : player(player), grid_size(grid_size){};
    ~GridConstrain();
    void apply();
};
#endif