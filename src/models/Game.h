#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "raylib.h"
#include "Knight.h"
#include "Level.h"
#include "../textures_container.h"
#include "../helpers/Log.h"

class Game
{
private:
    int screenWidth;
    int screenHeight;
    Knight *player;
    Level *level;
    TexturesContainer container;

    void loadTextures();
    void nextLevel();
    Knight *createPlayer();

public:
    Game(int screenWidth, int screenHeight);
    ~Game();
    static Game *make(int screenWidth, int screenHeight);
    void move();
    void draw();
    void setLevel(Level *level);
};

#endif // GAME_H_