#pragma once
#ifndef WALKABILITY_H_
#define WALKABILITY_H_

#include <iostream>
#include "Ability.h"
#include "../models/Sprite.h"

class WalkAbility : public Ability
{
private:
    Sprite *sprite;

public:
    WalkAbility(Sprite *sprite) : sprite(sprite){};
    ~WalkAbility();
    void apply();
};

#endif // WALKABILITY_H_
