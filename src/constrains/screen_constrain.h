#pragma once
#ifndef SCREEN_HEADER
#define SCREEN_HEADER

#include "raylib.h"
#include "constrain.h"
#include "../constants.h"
#include "../sprite.h"

class ScreenConstrain : public Constrain
{
private:
    Sprite *element;
    Rectangle screen;

public:
    ScreenConstrain(Sprite *element) : element(element){};
    void apply();
};

#endif