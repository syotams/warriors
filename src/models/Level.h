#pragma once
#ifndef LEVEL_HELPER
#define LEVEL_HELPER

#include <iostream>
#include "raylib.h"
#include "../helpers/ImageLoader.h"
#include "../helpers/Log.h"
#include "../Constants.h"
#include "SwordMan.h"
#include "Enemy.h"
#include "../textures_container.h"
#include "../constrains/DogChaseConstrain.h"

class Level
{
private:
    int screenWidth, screenHeight;
    const int TOTAL_IMAGES = 6;
    int positions[6];
    Texture2D backgrounds[6];
    Enemy *cpuPlayer;

    void loadBackgroundImages();

public:
    Level(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight){};
    ~Level();
    static Level *make(TexturesContainer *container, int screenWidth, int screenHeight);
    void addConstrainOn(Sprite *sprite);
    void detectCollisions(Sprite *sprite);
    void move();
    void draw();
};

#endif