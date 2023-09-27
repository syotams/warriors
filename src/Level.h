#pragma once
#ifndef LEVEL_HELPER
#define LEVEL_HELPER

#include <iostream>
#include "raylib.h"
#include "ImageLoader.h"
#include "Constants.h"

class Level
{
private:
    int screenWidth, screenHeight;
    Texture2D backgrounds[7];
    void loadImages();

public:
    Level(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight){};
    ~Level();
    static Level *make(int screenWidth, int screenHeight);
    void move();
    void draw();
};

#endif