#pragma once
#ifndef DOG_CHASER_HEADER
#define DOG_CHASER_HEADER

#include <iostream>
#include <cmath>
#include "../models/Sprite.h"
#include "Constrain.h"

class DogChaseConstrain : public Constrain
{
    Sprite *chaser;
    Sprite *chased;

public:
    DogChaseConstrain(Sprite *chaser, Sprite *chased) : chaser(chaser), chased(chased){};
    ~DogChaseConstrain();
    void apply() override;
};
#endif