#pragma once
#ifndef SCREEN_HEADER
#define SCREEN_HEADER

#include "raylib.h"
#include "Constrain.h"
#include "../Constants.h"
#include "../models/Sprite.h"

class ScreenConstrain : public Constrain
{
private:
    Sprite *element;
    int screenWidth;
    int screenHeight;

public:
    ScreenConstrain(Sprite *element, int screenWidth, int screenHeight) : element(element), screenWidth(screenWidth), screenHeight(screenHeight){};
    void apply() override;
};

#endif