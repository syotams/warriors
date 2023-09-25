#pragma once
#ifndef DOG_CHASER_HEADER
#define DOG_CHASER_HEADER

#include <iostream>
#include <cmath>
#include "../sprite.h"
#include "constrain.h"

class DogChaseConstrain : public Constrain
{
    Sprite *chaser;
    Sprite *chased;

public:
    DogChaseConstrain(Sprite *chaser, Sprite *chased) : chaser(chaser), chased(chased){};
    virtual ~DogChaseConstrain();
    void apply();
};
#endif